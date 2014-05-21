// #ifndef _LIGHT_H
// #define _LIGHT_H

// #include "Ray.h"

// class Light{
// private:
	// Point* origin;
	// Color* color;
	// float intensity;
	
// public:
	//Constructors
	// Light(Point* o, Color* col, float intens){
		// this->origin = o;
		// this->color = col;
		// this->intensity = intens;
	// }
	
	//Accessors
	// Point* getOrigin(){return this->origin;}
	// Color* getColor(){return this->color;}
	// float getIntensity(){return this->intensity;}
	
	
	 // getDiffuse()
	 // returns Color triple of the diffuse light value of object.
	
	// Color getDiffuse(Color &objectColor, float kD, Vect &S_incoming, Vect &Normal){
		// float norm_in = kD*((S_incoming).dotProduct(Normal));
		// return (objectColor*norm_in)*(lightColor);
	// }
	
	
	 // getAmbient()
	 // returns Color triple of the ambient light (Lambertian) value of object.
	
	// Color getAmbient(Color &objectColor, Color &ambientLight, float kA){
		// return objectColor*ambientLight*kA;
	// }
	
	
	 // getSpecular()
	 // returns Color triple of the specular light value of object.
	
	// Color getSpecular(Vect &R_perfect, Vect V_reverse, color &lightColor, color &objectColor, float kS, float kE){
		// float reflect_V = kS*(powf(R_perfect.dotProduct(V_reverse),kE));
		// return lightColor*objectColor*reflect_V;
	// }
	
	
	 // perfectReflect()
	 // returns Vect object that equates to the perfect reflection per input vector and normal of surface.
	
	// Vect perfectReflect(Vect &shadowRay, Vect &normal){
		// float rate = (2.0f*(shadowRay.dotProduct(normal))/(normal.getMagnitude()*normal.getMagnitude()));
		// return shadowRay-(normal*rate);
	// }
	
	
	 // getHalfWayVector()
	 // returns the halfway vector required for the Phong-Bling color output illumination
	 // where H = (L+V)/||L+V||, H being the halfway vector to return, L is the light ray-Vector, V is the camera's ray-Vector  
	
	// Vect getHalfWayVector(Vect &LightRay, Vect &CameraRay){
		// return (LightRay+CameraRay)/((LightRay+CameraRay).getMagnitude());
	// }
	
	
	
	 // illuminate()
	 // returns Color triple of all light components as per Phong illumination model.
	
	// Color illuminatePhong	(float kS, float kD, float kE, float kA,
							 // Vect &LightRay, Vect &CameraRay, Vect &normal, Vect	){
		// return getAmbient()+getDiffuse()+getSpecular();
	// }
	 
// };

// #endif
