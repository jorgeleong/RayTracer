// Ray Tracer project
// Spring 2014 - RIT
#include <iostream>
#include "BMPmaker.h"
#include "Ray.h"
#include "Triangle.h"
#include "Sphere.h"
#include "Light.h"

using namespace std;

// indexing value that will change with pixel traversal throughout viewing pane
// Gets x,y coordinates of pixel
int thisOne = 0;

int main (int argc, char *argv[]){
	cout << "rendering..." << endl;
	// Parameters to be read 
	int width = 640;
	int height = 480;
	int dpi = 72;
	
	// Parameters calculated from input
	int n = width*height;
	
	/* Vect p0 = Vect(0,0,0);
	Vect p1 = Vect(1,0,0);
	Vect p2 = Vect(1,0,1); */
	
	Vect p0 = Vect(-7,-1,0);
	Vect p1 = Vect(40,-1,0);
	Vect p2 = Vect(-7,-1,50);
	
	Color* red = new Color(1,0,0);
	// Triangle (Vect &p0, Vect &p1, Vect &p2, float dif, float spe, float emi, float tra, float ref, Color &col)
	Triangle* trial = new Triangle(p0, p1, p2, 0, 3, 0, 0, 0, *red);
	
	
	
	std::cout << "Specular of trial " << trial->getSpecular() << " Color: "<< trial->getColor()->getRed() << std::endl;
	std::cout << "Normal x=" << trial->getNormal()->getX() << " y="<< trial->getNormal()->getY() << " z="<<trial->getNormal()->getZ() << std::endl;
	delete trial;	
	
	Color *pixels = new Color[n];
	
	
	
	for (int x = 0; x < width ; x++){
		for (int y = 0; y < height ; y++){
		
		thisOne = y*width + x ;
		
		if((x > 200 && x <440)&& (y > 200 && y < 280)){
			pixels[thisOne].setRed(13);
			pixels[thisOne].setGreen(223);
			pixels[thisOne].setBlue(40);
				
		}
		else {
			pixels[thisOne].setRed(0);
			pixels[thisOne].setGreen(0);
			pixels[thisOne].setBlue(0);
		}
		
		
		}
	}
	
	saveBMP("scene.bmp",width,height,dpi,pixels);
	//delete pixels;
	return 0;
}
