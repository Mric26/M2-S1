#ifndef IMPLICIT_FUNCTION_H
#define IMPLICIT_FUNCTION_H

#include <glm/glm.hpp>
#include <glm/gtc/type_precision.hpp> //i32vec3
#include <vector>
#include <string>


class PerlinNoise
{
public:

    PerlinNoise(const glm::uint nb_octave = 3, const float persistency = 0.5);
    ~PerlinNoise();


    double Eval(glm::vec3 p) const;


    static double grad3( int hash, double x, double y , double z );
    static double snoise3(double x, double y, double z);
    static double noise(const glm::vec3& x,int octave,double persistency);


private:

    glm::uint m_nb_octave;
    float m_persistency;

    static const unsigned char perm[512];
};




#endif // IMPLICIT_FUNCTION_H
