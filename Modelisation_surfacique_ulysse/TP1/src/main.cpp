
// std includes
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>


// GL include
#include <GL/glew.h>    // OpenGL Extension Wrangler Library : http://glew.sourceforge.net/ 
#include <GL/glfw.h>    // Window, keyboard, mouse : http://www.glfw.org/

// glm include
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/ext.hpp>

// local include
#include "shader.h"         // Help to load shaders from files
#include "GLFW_define.h"    // Some macros for the interface
#include "Mesh.h"
#include "Object.h"
#include "ImplicitFunction.h"

#include "MyImplicitSphere.h"
#include "MyImplicitCylindre.h"
#include "MyImplicitTore.h"
#include "MyImplicitAddition.h"
#include "MyImplicitSoustraction.h"
#include "MyImplicitIntersection.h"
#include "reconstructionsurface.h"

// Window size :
#define WIDTH 1000.0f
#define HEIGHT 800.0f

using namespace glm;
using namespace std;


void view_control(mat4& view_matrix, float dx);

int main()
{

    cout << "Starting program..." << endl;

    //==================================================
    //============= Creation de la fenetre =============
    //==================================================


    // GLFW initialization
    if( !glfwInit() )
    {
        cerr << "Failed to initialize GLFW!" << endl;
        exit(EXIT_FAILURE);
    }

    glfwOpenWindowHint(GLFW_FSAA_SAMPLES, 4); // Anti Aliasing
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MAJOR, 3); // OpenGL 3.1
    glfwOpenWindowHint(GLFW_OPENGL_VERSION_MINOR, 1);

    // Window and OpenGL conetxt creation
    if( !glfwOpenWindow(WIDTH, HEIGHT, 0,0,0,0, 32,0, GLFW_WINDOW ) )
//    if( !glfwOpenWindow(WIDTH, HEIGHT, 0,0,0,0, 32,0, GLFW_FULLSCREEN ) )
    {
        cerr << "GLFW failed to open OpenGL window!" << endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // GLFW Settings
    glfwSetWindowTitle( "TP 1 3A Ensimag - MS - Implicit Functions" );
    glfwEnable( GLFW_STICKY_KEYS );

    // GLEW Initialization
    if (glewInit() != GLEW_OK) {
        cerr << "Failed to intialize GLEW:!" << endl;
        exit(EXIT_FAILURE);
    }
    


    // Soft- and Firm-ware checkings
    const GLubyte* renderer = glGetString (GL_RENDERER);
    cout << "GPU : " << renderer << endl;

    const GLubyte* version = glGetString (GL_VERSION);
    cout << "OpenGL Driver : " << version << endl;


    cout << endl;


    //==================================================
    //================= Initialization =================
    //==================================================

    cout << "Initializing..." << endl;



    //-------------------------------------------------
    // OpenGL Initialization

    glClearColor(0.1, 0.1, 0.1, 1.0);
//    glClearColor(1.0, 1.0, 1.0, 1.0);
    glEnable(GL_DEPTH_TEST);



    //-------------------------------------------------
    // Shader program initialization

    GLuint programID = LoadShaders( "../shader/vertex.glsl",      "../shader/fragment.glsl" );
    cout << "programID = " << programID << endl;


    //-------------------------------------------------
    // Object Initialization


    //**********************************************************************************
    //
    // TODO : call your implicit function class here to generate your object
    //
    //**********************************************************************************

    MyImplicitFunction f;
    MyImplicitSphere s;
    MyImplicitCylindre c;
    MyImplicitTore t;
    MyImplicitAddition *a = new MyImplicitAddition(&t, &c);
    //MyImplicitSoustraction *b = new MyImplicitSoustraction(&t, &c);
    MyImplicitIntersection *i = new MyImplicitIntersection(&t, &c);
    
    //**********************************************************************************
    //
    // TODO : call the marching tetrahedra algorithm on your implicit function
    //
    //**********************************************************************************

    Mesh m;
    Mesh::CreateCube(m);        // This is a place holder, comment it

    //ReconstructionSurface rs(m);
    Mesh::CreateIsoSurface(m, c, 0.5);
    
    //**********************************************************************************

    cout << "Created mesh with " << m.vertices.size() << " vertices and " << m.faces.size() << " faces." << endl;

    m.write_obj("../output/my_surface.obj");    // your mesh will be exported (incase you need to visualize it with an other software)

    // Object creation
    Object o;
    o.GenBuffers();
    o.SetMesh(m);
    o.SetShader(programID);


    //-------------------------------------------------
    // MVP matrix initialization

    mat4 projection_matrix = perspective(45.0f, WIDTH / HEIGHT, 0.1f, 100.0f);
    mat4 view_matrix = lookAt(vec3(1.0, 2.0, 1.0), vec3(0.0), vec3(0.0, 0.0, 1.0));

    GLuint PmatrixID = glGetUniformLocation(programID, "ProjectionMatrix");
    cout << "PmatrixID = " << PmatrixID << endl;

    GLuint VmatrixID = glGetUniformLocation(programID, "ViewMatrix");
    cout << "VmatrixID = " << VmatrixID << endl;
    


    cout << "Initializing done." << endl;
    cout << endl;
    


    //==================================================
    //==================== Main Loop ===================
    //==================================================


    cout << "Starting main loop..." << endl;

    double init_time = glfwGetTime();
    double prec_time = init_time;
    double cur_time = init_time;
    double speed = 2.0;

    do{
        // Clearing Viewport
        glClear( GL_COLOR_BUFFER_BIT );
        glClear( GL_DEPTH_BUFFER_BIT );



        //==================================================
        //================== Computations ==================
        //==================================================

        prec_time = cur_time;
        cur_time = glfwGetTime() - init_time;
        float delta_time = cur_time - prec_time;

        view_control(view_matrix, speed * delta_time);



        //==================================================
        //===================== Drawing ====================
        //==================================================


        o.Draw(view_matrix, projection_matrix, VmatrixID, PmatrixID);

        glfwSwapBuffers();




        //==================================================
        //================== Stats Display =================
        //==================================================

        cout.precision(2);
        cout<< fixed  << "FPS: " << 1.0 / delta_time << "\t---\tElapsed time: " << setw(8) << cur_time << "\ts\r" << flush;

    }
    while( glfwGetKey( GLFW_KEY_ESC ) != GLFW_PRESS &&
           glfwGetWindowParam( GLFW_OPENED )        );

    // Closing the window
    glfwTerminate();


    cout << endl << endl << "Main loop ended." << endl;


    cout << "Program ended." << endl;


    return EXIT_SUCCESS;
}




void view_control(mat4& view_matrix, float dx)
{
    if (glfwGetKey( GLFW_KEY_LSHIFT ) == GLFW_PRESS)
    {
        dx /= 10.0;
    }

    if (glfwGetKey( GLFW_KEY_UP ) == GLFW_PRESS)
    {
        vec4 axis = vec4(1.0, 0.0, 0.0, 0.0);
        axis = inverse(view_matrix) * axis;
        view_matrix = rotate(view_matrix, dx * 180.0f, vec3(axis));
    }
    if (glfwGetKey( GLFW_KEY_DOWN ) == GLFW_PRESS)
    {
        vec4 axis = vec4(1.0, 0.0, 0.0, 0.0);
        axis = inverse(view_matrix) * axis;
        view_matrix = rotate(view_matrix, -dx * 180.0f, vec3(axis));
    }
    if (glfwGetKey( GLFW_KEY_RIGHT ) == GLFW_PRESS)
    {
        vec4 axis = vec4(0.0, 1.0, 0.0, 0.0);
        axis = inverse(view_matrix) * axis;
        view_matrix = rotate(view_matrix, dx * 180.0f, vec3(axis));
    }
    if (glfwGetKey( GLFW_KEY_LEFT ) == GLFW_PRESS)
    {
        vec4 axis = vec4(0.0, 1.0, 0.0, 0.0);
        axis = inverse(view_matrix) * axis;
        view_matrix = rotate(view_matrix, -dx * 180.0f, vec3(axis));
    }
    if (glfwGetKey( GLFW_KEY_PAGEUP ) == GLFW_PRESS)
    {
        vec4 axis = vec4(0.0, 0.0, 1.0, 0.0);
        axis = inverse(view_matrix) * axis;
        view_matrix = rotate(view_matrix, dx * 180.0f, vec3(axis));
    }
    if (glfwGetKey( GLFW_KEY_PAGEDOWN ) == GLFW_PRESS)
    {
        vec4 axis = vec4(0.0, 0.0, 1.0, 0.0);
        axis = inverse(view_matrix) * axis;
        view_matrix = rotate(view_matrix, -dx * 180.0f, vec3(axis));
    }

    if (glfwGetKey( GLFW_KEY_Z ) == GLFW_PRESS)
    {
        vec3 pos = vec3(view_matrix * vec4(0,0,0,1));
        vec4 axis = vec4(0.0, 0.0, 1.0, 0.0) * dx * length(pos) * 0.5;
        axis = inverse(view_matrix) * axis;
        view_matrix = translate(view_matrix, vec3(axis));
    }
    if (glfwGetKey( GLFW_KEY_S ) == GLFW_PRESS)
    {
        vec3 pos = vec3(view_matrix * vec4(0,0,0,1));
        vec4 axis = vec4(0.0, 0.0, 1.0, 0.0) * (-dx) * length(pos) * 0.5;
        axis = inverse(view_matrix) * axis;
        view_matrix = translate(view_matrix, vec3(axis));
    }
    if (glfwGetKey( GLFW_KEY_Q) == GLFW_PRESS)
    {
        vec4 axis = vec4(-1.0, 0.0, 0.0, 0.0) * dx;
        axis = inverse(view_matrix) * axis;
        view_matrix = translate(view_matrix, vec3(axis));
    }
    if (glfwGetKey( GLFW_KEY_D ) == GLFW_PRESS)
    {
        vec4 axis = vec4(-1.0, 0.0, 0.0, 0.0) * (-dx);
        axis = inverse(view_matrix) * axis;
        view_matrix = translate(view_matrix, vec3(axis));
    }
    if (glfwGetKey( GLFW_KEY_A ) == GLFW_PRESS)
    {
        vec4 axis = vec4(0.0, 1.0, 0.0, 0.0) * dx;
        axis = inverse(view_matrix) * axis;
        view_matrix = translate(view_matrix, vec3(axis));
    }
    if (glfwGetKey( GLFW_KEY_E ) == GLFW_PRESS)
    {
        vec4 axis = vec4(0.0, 1.0, 0.0, 0.0) * (-dx);
        axis = inverse(view_matrix) * axis;
        view_matrix = translate(view_matrix, vec3(axis));
    }
}


