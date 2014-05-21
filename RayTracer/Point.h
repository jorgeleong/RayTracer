/*
	Point class, for storing 3 dimensional point data
	Type of class: Auxiliary.
*/

#ifndef _POINT_H
#define _POINT_H

#include <vector>
#include "Color.h"

class Point {
private:
	float x;
    float y;
    float z;
	
public:
	Point::Point(){
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
	}

	Point::Point(float x, float y, float z){
		this->x = x;
		this->y = y;
		this->z = z;
		
	}

	// Accessors
	float Point::getX() const {return this->x;}
	float Point::getY() const {return this->y;}
	float Point::getZ() const {return this->z;}

	// Point distance
	float Point::distance(Point &x){
		return sqrtf(powf((x-*this).getX(), 2)+
					 powf((x-*this).getY(), 2)+
					 powf((x-*this).getZ(), 2));
	}

	// Subtract overload - configure the color input 
	Point Point::operator-(const Point &input){
		return Point(this->x - input.getX(), this->y - input.getY(), this->z - input.getZ());
	}
};

#endif
