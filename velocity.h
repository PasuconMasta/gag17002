#ifndef VELOCITY_H
#define VELOCITY_H

#include "point.h"
#include "velocity.h"

// Put your velocity class here, or overwrite this file with your own
// velocity class from the previous project
class Velocity {
private:
	float dx;
	float dy;
	
	


public:

	Velocity()
	{
		dx = 0.0;
		dy = 0.0;

	}

	float getDx() { return dx; }
	float getDy() { return dy; }

	
	void setDx(float dx) { this->dx = dx; }
	void setDy(float dy) { this->dy = dy; }

	



};



#endif /* velocity_h */
