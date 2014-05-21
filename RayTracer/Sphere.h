#ifndef _SPHERE_H
#define _SPHERE_H

#include "Object.h"

class Sphere : public Object{
private:
	Vect* center;
	float radius;
		
public:
	// Constructors
	
	// Class methods
	Vect* intersect(Ray* ray){return new Vect();}
	// virtual void transform(fMatrix* matrix){} to be entered later
};

#endif
