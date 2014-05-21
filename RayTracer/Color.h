/*
	Color class, when instantiated holds a triple of float values
	that will provide information on colour for each pixel.
	Type of class: Essential
*/
#ifndef _COLOR_H
#define _COLOR_H
#include <iostream>
#include <math.h>

class Color{
	private:
		float r;
		float g;
		float b;
		float magnitude;
		
	public:
		/*
		Consider making the color parameters a value from 0 to 1 
		then make sure to normalize the colors.
	 */

	// Default object
	Color::Color(){
		this->r = 0.0f;
		this->g = 0.0f;
		this->b = 0.0f;
	}

	/*
		Color constructor takes any value for red, green and blue
		calculates the magnitude and normalizes the values for r, g and b.
		ALWAYS CALCULATE VALUES FIRST
	 */
	Color::Color (float red, float green, float blue){
		this->magnitude = sqrtf((powf(red, 2))+(powf(green,2))+(powf(blue, 2)));
		this->r = red/magnitude;
		this->g = green/magnitude;
		this->b = blue/magnitude;
		
	}

	// Accessors
	float Color::getRed(){ return this->r;}
	float Color::getGreen(){ return this->g;}
	float Color::getBlue(){return this->b;}

	// Mutators
	void Color::setRed(float red){this->r = red;}
	void Color::setGreen(float green){this->g = green;}
	void Color::setBlue(float blue){this->b = blue;}

	/*
	 normalizeC will normalize color values in case one gets changed
	 */
	void Color::normalizeC(){
		this->magnitude = sqrtf((powf(r, 2))+(powf(g,2))+(powf(b, 2)));
		r = r/magnitude;
		g = g/magnitude;
		b = b/magnitude;
	}

	Color Color::Clip(){
		// Avoid changing the value of the color referenced
		float red = this->getRed();
		float green = this->getGreen();
		float blue = this->getBlue();
		
		// Get the value of all the color components
		float light = red + green + blue;
		
		// Check for excess and recalculate color based
		float excess = light - 3;
		if (excess > 0) {
			red += excess*(red/light);
			green += excess*(green/light);
			blue += excess*(blue/light);
		}
		
		// Bounding section - get rid of excess
		if (red > 1)    {red = 1;}
		if (blue > 1)   {green = 1;}
		if (green > 1)  {blue = 1;}
		
		// Bounding section - negative becomes zero
		if (red < 0)    {red = 0;}
		if (blue < 0)   {green = 0;}
		if (green < 0)  {blue = 0;}
		
		return Color(red, green, blue);
	}

	// Operator overload
	// Multiplication overload for scalars
	Color Color::operator*(float &input){
		return Color(this->r*input,
					 this->g*input,
					 this->b*input);
	}

	// Multiplication overload for color triples
	Color Color::operator*(const Color &input){
		return Color();
	}

	// Multiplication overload for color triples
	Color Color::operator+(const Color &input){
		return Color(this->r+input.r,
					 this->g+input.g,
					 this->b+input.b);
	}

};


#endif
