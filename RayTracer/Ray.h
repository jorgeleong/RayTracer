/*
	Ray class will provide vectorial information about rays emitted
	from an origin (vect instance).
	Type of class: Essential
*/
#ifndef _RAY_H
#define _RAY_H

#include "Vect.h"

class Ray{
private:
	Vect origin;
    Vect direction;
    
public:
	// Empty Ray constructor
	Ray::Ray(){
		origin = Vect(0,0,0);
		direction = Vect(1,0,0);
	}
	// Preferred constructor
	Ray::Ray(Vect o, Vect d){
		this->origin = o;
		this->direction = d;
	}
	// Accessors
	Vect Ray::getOrigin() const {return this->origin;}
	Vect Ray::getDirection(){return this->direction;}
	// Mutators
	void Ray::setOrigin(Point &o){this->origin = o;}
	void Ray::setDirection(Vect &d){this->direction = d;}
	
};

#endif
