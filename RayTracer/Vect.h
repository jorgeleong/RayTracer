/*
	Vect is a class that represents a vector in space
	Type of class: Auxiliary.
*/

#ifndef _VECT_H
#define _VECT_H

#include "Point.h"

class Vect{
private:
    float x;
    float y;
    float z;
    float magnitude;
public:
	
	Vect::Vect(){
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
		this->magnitude = sqrtf((this->x*this->x)+(this->y*this->y)+(this->z*this->z));
	}

	// Float input constructor
	Vect::Vect (float i, float j, float k){
		this->x = i;
		this->y = j;
		this->z = k;
		this->magnitude = sqrtf((this->x*this->x)+(this->y*this->y)+(this->z*this->z));
	}

	// 1 Point input constructor
	Vect::Vect (Point &location){
		this->x = location.getX();
		this->y = location.getY();
		this->z = location.getZ();
		this->magnitude = sqrtf((this->x*this->x)+(this->y*this->y)+(this->z*this->z));
	}

	// 2 Point input constructor
	Vect::Vect (Point &origin, Point &destination){
		this->x = (destination-origin).getX();
		this->y = (destination-origin).getY();
		this->z = (destination-origin).getZ();
		this->magnitude = sqrtf((this->x*this->x)+(this->y*this->y)+(this->z*this->z));
	}
	
	// 2 Vect input constructor
	Vect::Vect (Vect &origin, Vect&destination){
		this->x = (destination-origin).getX();
		this->y = (destination-origin).getY();
		this->z = (destination-origin).getZ();
		this->magnitude = sqrtf((this->x*this->x)+(this->y*this->y)+(this->z*this->z));
	}

	// Accessors
	float Vect::getX() const {return this->x;}
	float Vect::getY() const {return this->y;}
	float Vect::getZ() const {return this->z;}
	float Vect::getMagnitude() const {return this->magnitude;}

	// Addition overload
	Vect Vect::operator+(const Vect &input){
		return Vect(this->x+ input.getX(), this->y + input.getY(), this->z+ input.getZ());
	}

	// Subtract overload
	Vect Vect::operator-(const Vect &input){
		return Vect(this->x - input.getX(), this->y - input.getY(), this->z - input.getZ());
	}

	// Equals overload for scalars
	Vect Vect::operator=(const Vect &input){
		this->x = input.getX();
		this->y = input.getY();
		this->z = input.getZ();
		return *this;
	}

	// Multiplication overload for scalars
	Vect Vect::operator*(float &input){
		return Vect(this->x*input, this->y*input, this->z*input);
	}

	// Division overload for scalars
	Vect Vect::operator/(float &input){
		return Vect(this->x/input, this->y/input, this->z/input);
	}

	// Cross Product operation returns Vect
	Vect Vect::crossProduct(const Vect &input){			// this->Vect is u, input is v
		return Vect(this->y*input.z - this->z*input.y,  // for x = Uy*Vz - Uz*Vy
					this->z*input.x - this->x*input.z,	// for y = Uz*Vx - Ux*Vz
					this->x*input.y - this->y*input.x); // for z = Ux*Vy - Uy*Vx
	}

	// Dot Product operation returns float
	float Vect::dotProduct(const Vect &input){
		return (this->x * input.getX() +
				this->y * input.getY() +
				this->z * input.getZ());
	}

	// Vector normalizer
	Vect Vect::normalizeV(){
	/* 	this->x /= this->magnitude;
		this->y /= this->magnitude;
		this->z /= this->magnitude;
		this->magnitude = sqrtf((this->x*this->x)+(this->y*this->y)+(this->z*this->z));
 */		return Vect(this->getX()/this->magnitude, this->getY()/this->magnitude, this->getZ()/this->magnitude); 
	}

	// Reverse the vector
	void Vect::reverseVector(){
		this-> x = -(this->getX());
		this-> y = -(this->getY());
		this-> z = -(this->getZ());
	}

	// Angle between two vectors
	float Vect::getAngle(Vect &X){
		float numerator = this->dotProduct(X);
		float denominator = (float)ceil(this->getMagnitude() * X.getMagnitude());
		return acosf(numerator/denominator)*(180.0f/M_PI);
	}

};

#endif
