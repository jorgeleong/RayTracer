#ifndef _TRIANGLE_H
#define _TRIANGLE_H

#include "Object.h"

class Triangle: public Object {
private:
	Vect* point0;
	Vect* point1;
	Vect* point2;
	
	Vect* e1;
	Vect* e2;
	Vect* normal;
		
public:
	// Constructors
	Triangle(){
		this->point0 = NULL;//Vect();
		this->point1 = NULL;//Vect();
		this->point2 = NULL; //Vect();
		this->color = NULL;
	}
	
	// Default destructor
	~Triangle(){
		delete point0;
		delete point1;
		delete point2;
		delete e1;
		delete e2;
		delete normal;
	}
	
	// Using the base class constructor 
	Triangle (Vect &p0, Vect &p1, Vect &p2, 
						float dif, float spe, float emi, 
						float tra, float ref, Color &col):Object(dif, spe, emi, tra, ref, col){
		
		this->point0 = new Vect(p0.getX(),p0.getY(),p0.getZ());
		this->point1 = new Vect(p1.getX(),p1.getY(),p1.getZ());
		this->point2 = new Vect(p2.getX(),p2.getY(),p2.getZ());
		
		this->e1 = new Vect((p1 - p0).normalizeV());	// e1 = p1 - p0
		this->e2 = new Vect((p2 - p0).normalizeV());	// e2 = p2 - p0	
		
		this->normal = new Vect((*e2).crossProduct(*e1).normalizeV()); // cross product of e2 and e1 gives up normal
	}
	
	// Accessors 
	Vect* getNormal(){return this->normal;}
	
	// Class methods
	Vect* intersect(Ray* ray){
		Vect dir = ray->getDirection();
		Vect Orig = ray->getOrigin();

		Vect T = Orig - *(this->point0);
		Vect P = dir.crossProduct(*(this->e2));
		Vect Q = T.crossProduct(*(this->e1));
		 
		float parallelCheck = (P.dotProduct(*(this->e1)));
		if (parallelCheck == 0 + 0.00000001f){
			return NULL;
		}
		 
		float commonDivisor = 1/parallelCheck;
		// Barycentric parameters
		float t = commonDivisor*(Q.dotProduct(*(this->e2)));
		// Check if intersection point is outside of triangle
		if (t < 0){ return NULL;}
		 
		float u = commonDivisor*(P.dotProduct(T));
		float v = commonDivisor*(Q.dotProduct(dir));
		// Check if u is less than 0 - condition for intersection
		if (u < 0 || v< 0 || u+v >1){ return NULL;}		
		else
			return new Vect();
		 
		}
	// virtual void transform(fMatrix* matrix){} to be entered later
};

#endif
