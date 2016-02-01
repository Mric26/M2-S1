precision highp float;

#define PI 3.1415926535897932384626433832795

in vec2 texcoord;

// Parametres de la lumiere
vec3 posLight = vec3(xLight, yLight, zLight);

vec3 backColor = vec3(0.15,0.15,0.15);
int nb_iter_max = 500;
float dt = 0.1;
float d_min = 0.0;
float d_max = 50;
float epsi = 0.05;


struct Base3D{
	vec3 right;
	vec3 up;
	vec3 view;
};

struct Cam{
	vec3 ro; 			//origine
	Base3D base;
	float angle;		//angle d'ouverture
	float ratio;		//ration long/larg
};

struct Ray{
	vec3 ro;		//point origine
	vec3 rd;		//vecteur directionnel
};


//// Objet 3D ////
struct Plan{
	vec3 n; 			//normal
	float d; 			//offset
	vec3 color; 		//couleur
};

struct Sphere{
	vec3 ro; 					//origine
	float ra; 					//rayon
	vec3 color;					//couleur
};

struct Torus{
	vec3 ro;
	float R;
	float r;
};

struct Capsule{
	vec3 a;
	vec3 b;
	float r;
};

struct resP{
	float x;
	vec3 y;
};

//// Implicit Fonction ////
float implicitPlan( vec3 p, Plan plan ){
	return dot(p,plan.n) + plan.d;
}

float implicitSphere( vec3 p, Sphere s ){
 	return length(p-s.ro) - s.ra;
}

float implicitTorus( vec3 p, Torus t ){
	vec2 q = vec2( length(p.xz - t.ro.xz) - t.R, p.y - t.ro.y );
	return length(q) - t.r;
}

float implicitCapsule( vec3 p, Capsule c ){
	vec3 pa = p - c.a;
	vec3 ba = c.b - c.a;
	float h = clamp( dot(pa,ba)/dot(ba,ba), 0.0, 1.0 );
	return length( pa - ba*h ) - c.r;
}


//// Operateur ////
float opUnion(float d1, float d2) {
	return min( d1, d2 );
}

float opIntersection(float d1, float d2) {
	return max(d1, d2);
}

float opSoustraction(float d1, float d2) {
	return max(d1, -d2);
}

float opBlend( float d1, float d2, float k ){
    float res = exp( -k*d1 ) + exp( -k*d2 );
    return -log( res )/k;
}

mat3 rotationZ(float radian){
	return mat3(
   		 cos(radian), sin(radian), 0.0, 	// first column (not row!)
   		-sin(radian), cos(radian), 0.0, 	// second column
   		0.0, 0.0, 1.0  						// third column
	);
}

mat3 scale( float sx, float sy, float sz ){
	return mat3(
		sx, 0.0, 0.0, // first column (not row!)
		0.0, sy, 0.0, // second column
		0.0, 0.0, sz  // third column
	);
}

//// Fonction de distance de la scene ////
resP distanceField( vec3 pos ) {
	Plan p = Plan( vec3(0,0,1), 0, vec3(1,0,0) );
	Sphere s = Sphere(vec3(1,0,1), 1, vec3(1,0,1));

	// Scene initiale, Plan + Sphere
	float resp, ress;
	resp = implicitPlan( pos, p );
	ress = implicitSphere(pos, s);

	resP res;
	if( resp < ress ){
		res = resP( resp, p.color);
	}
	else{
		res = resP( ress, s.color);
	}

	return res;
}

// Recherche d'une intersection de la source du rayon jusqu'a une distance max
resP computeIntersection( Ray ray, float distMax ){
	float t = 0;
	float ft, ft_old;
	while (t < distMax) {
		vec3 pos = ray.ro + (t * ray.rd);
		resP df = distanceField( pos );
		ft = df.x;
		if (ft < 0) {
			if (t == 0) {	// Cas limite ou la source du rayon est a l'interieur du champ
				return resP(0,vec3(0,0,0));
			}
			return resP(t - dt, df.y);
		}
		t += dt;
		ft_old = ft;
	}
	// On retourne -1 si le champ n'a pas été intersecté
	return resP(-1,vec3(0,0,0));
}

// Calcul du coefficient d'ombre (methode d'iquilezles)
float softShadow( Ray ray, float distMax, float k ){
	float t = 0;
	float res = 1.0;
	while (t < distMax) {
		vec3 pos = ray.ro + (t * ray.rd);
		float ft = (distanceField( pos )).x;
		if (ft <= 0) {
			return 0.0;	// On retourne 0 si un objet est intersecté
		}
		res = min( res, k * ft/t );
		t += dt;
	}
	// On retourne la distance minimale entre le rayon et le champ scalaire
	return res;
}

// Calcul de la normale
vec3 computeNormale( vec3 pos ){
	float dx = (distanceField( vec3(pos.x+epsi, pos.y, pos.z) )).x - (distanceField( vec3(pos.x-epsi, pos.y, pos.z) )).x;
	float dy = (distanceField( vec3(pos.x, pos.y+epsi, pos.z) )).x - (distanceField( vec3(pos.x, pos.y-epsi, pos.z) )).x;
	float dz = (distanceField( vec3(pos.x, pos.y, pos.z+epsi) )).x - (distanceField( vec3(pos.x, pos.y, pos.z-epsi) )).x;
	return normalize( vec3(dx, dy, dz) );
}


// Rendu de profondeur
vec3 renderDepth(  float t  ) {
	return vec3(t/d_max, t/d_max, t/d_max);
}

// Rendu des normales
vec3 renderNormale( vec3 pos ) {
	return computeNormale( pos );
}

// Rendu avec lumiere et ombres
vec3 renderShadow( vec3 pos ) {
	vec3 normale = computeNormale( pos );

	// Caclcul du coefficient de l'ombre
	vec3 shadowDir = normalize( vec3(posLight - pos) );
	Ray shadowRay = Ray( pos+shadowDir/4, shadowDir );
	float shadowCoef = softShadow( shadowRay, length(posLight - pos), 8 );

	// Calcul de l'eclairement
	vec3 dirLight = normalize( vec3(pos - posLight) );
	float intensity = - (min( 0, dot( normale, dirLight ) ) - 0.20 );

	// rendu final de la lumiere
	return shadowCoef * (intensity * normale);
}

vec3 BRDF( vec3 l, vec3 v, vec3 n, vec3 coul ){
	vec3 f0 = vec3(1,1,1); 
	vec3 h = normalize( l + v );
	vec3 m = h / 2;
	float alpha = 1;
	//lumière diffuse
	vec3 diff = coul / PI;
	//lumière speculaire
	vec3 Fresnel = f0 + (1 - f0) * pow( 1 - dot(l, h), 5 );
	float GImplicit = dot( n, l ) * dot( n, v );
	float D = ( (alpha + 2) / (2 * PI) ) * pow( dot( n, m ), alpha ) ;
	vec3 spec = (Fresnel * GImplicit * D) / (4 * GImplicit)  ;
	//resultat
	return diff + spec;
}

vec3 directIllumination( vec3 pos, Cam c, vec3 coul ){
	// Calcul de la BRDF
	vec3 normale = computeNormale( pos );
	/*if ( distanceField(pos) < 0) {
		return vec3(1,0,0);
	}*/
	vec3 dirLight = normalize( vec3(posLight - pos) );
	vec3 BRDF = BRDF( dirLight, normalize(c.ro - pos), normale, coul );
	float k = dot(normale, dirLight);
	if( k < 0 ){
		k = 0;
	}
	// Equation de la reflectance
	vec3 res = PI * BRDF * k;
	// Caclcul du coefficient de l'ombre
	vec3 shadowDir = normalize( vec3(posLight - pos) );
	Ray shadowRay = Ray( pos+shadowDir/4, shadowDir );
	float shadowCoef = softShadow( shadowRay, length(posLight - pos), 8 );
	// Couleur de sortie
	return shadowCoef * res;
}

vec3 color_trace( Ray ray, Cam c  ){
	float c_refl = 0.4;
	vec3 accum = vec3(0,0,0);
	vec3 mask = vec3(1,1,1);
	vec3 pos, color;
	for( int i = 0; i <10; i++){
		resP ci = computeIntersection( ray, d_max );
		float t = ci.x;
		if ( t != -1 ) {
			pos = ray.ro + (t * ray.rd);
			if ( (distanceField( pos )).x < 0 ) {
				return vec3(1, 0, 1);
			}
			color = directIllumination(pos , c, ci.y);
			accum = accum + (mask * color);
			mask = c_refl * mask;
			ray = Ray(pos, reflect(ray.rd, computeNormale(pos) ) );
		} else {
			return accum;
		}
	}
	return accum;
}

void main() {
	//// camera ////
	float xCam = module * cos(azimut) * cos(elevation);
	float yCam = module * sin(azimut) * cos(elevation);
	float zCam = module * sin(elevation);
	vec3 up = normalize ( vec3(0,0,1) );
	vec3 view = normalize ( -vec3(xCam,yCam,zCam) );
	vec3 right = normalize ( cross(view, up) );
	up = normalize ( cross(right, view) );
	Base3D b = Base3D(right, up, view);
	Cam c = Cam( vec3(xCam, yCam, zCam), b, PI/2, 4.0/4.0);
	
	//// Ray tracing ////
	float D = 1.0 / tan( c.angle/2.0 );
	vec2 normalCoord = ( 2.0 * (gl_FragCoord.xy / vec2(512.0, 512.0)) ) - 1;	// Coordonnees du pixel entre [-1 1]x[-1 1]
	vec3 dr = normalize( (normalCoord.x * b.right) + ((c.ratio * normalCoord.y) * b.up) + (D * b.view) );
	Ray ray =  Ray ( c.ro, dr );

	vec3 color = backColor;
	float t = (computeIntersection( ray, d_max )).x;
	if (t != -1) {
			color = color_trace(ray, c);
	}

	outBuffer0 = vec4(color, 1);
}
