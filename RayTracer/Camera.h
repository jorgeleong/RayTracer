/*
	Camera class will provide vectorial information about Cameras emitted
	from an origin (vect instance).
	Type of class: Essential
*/
#ifndef _Camera_H
#define _Camera_H

#include "Ray.h"

class Camera{
private:
    // Look at variable
    Point* lookAt;
    // Camera's position in World space
    Point* position;
    // Up direction of camera
    Vect* up;
    
    // Focal length of the camera
    float focalL;
    // The view matrix for transforming into camera space
    // fMatrix* viewMatrix;
    
public:
	// Empty Camera constructor
	Camera::Camera(){
		origin = Vect(0,0,0);
		direction = Vect(1,0,0);
		up = Vect(0,1,0);
	}
	// Preferred constructor
	Camera::Camera(Vect o, Vect d){
		this->origin = o;
		this->direction = d;
	}
	// Accessors
	Vect Camera::getOrigin() const {return this->origin;}
	Vect Camera::getDirection(){return this->direction;}
	// Mutators
	void Camera::setOrigin(Point &o){this->origin = o;}
	void Camera::setDirection(Vect &d){this->direction = d;}
	
};

#endif
8