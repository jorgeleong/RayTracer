/*
	Object class
	Base class for all elements in scene 
	All objects have the following properties/fields:
		-> A color
		-> And specular, emissive, diffuse, transmissive and reflective constants
	All objects also will inherit virtual methods that will be overridden at each Object:
		-> accessors for all fields
		-> intersect function (virtual)
		-> transform function (virtual)
*/

#ifndef _OBJECT_H
#define _OBJECT_H

#include "Ray.h"
#include "Color.h"

class Object {
protected:
	float kS, kE, kD;
	float kT, kR;
	Color* color;
		
public:
	// Default constructor 
	Object(){
		kS = 0; 
		kE = 0; 
		kD = 0;
		kT = 0; 
		kR = 0;
		this->color = new Color();
	}
	
	virtual ~Object(){}
	
	// Constructor will be called later
	Object(float d, float s, float e, float T, float R, Color &col)
			: kD(d), kS(s), kE(e), kT(T), kR(R), color(new Color(col)){
	}
	// Access methods
	virtual float getSpecular(){return kS;}
	virtual float getEmissive(){return kE;}
	virtual float getDiffuse(){return kD;}
	virtual float getTransmissive(){return kT;}
	virtual float getReflective(){return kR;}
	virtual Color* getColor(){return this->color;}
	
	// Mutator method
	//virtual void setColor(Color* col){this->color = col;}
	
	// Class methods  - all objects have intersection
	virtual Vect* intersect(Ray* ray) = 0;//{return new Vect();}
	// virtual void transform(fMatrix* matrix){} to be entered later
};

#endif
