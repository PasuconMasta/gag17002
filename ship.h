#ifndef ship_h
#define ship_h

#include "flyingObject.h"
#include "point.h"
#include "velocity.h"
#include "uiDraw.h"

#define SHIP_SIZE 10

#define ROTATE_AMOUNT 6
#define THRUST_AMOUNT 0.5



// Put your Ship class here
class Ship : public FlyingObject
{
private:
	bool isThrust;
	float direction;
	float speed;

public:
	Ship() { angle = 0; setRadius(0); direction = 0; setAlive(true); point.setX(0); point.setY(0); }
	
	
	bool getIsThrust() { return isThrust; }
	float getDirection() { return direction;  }

	
	
	void setIsThrust(bool input) { this->isThrust = input; }

	void turnRight();
	void turnleft();
	void thurst();
	void fire(Point point, float angle);
	void advance();


	void draw() { drawShip(point, direction, isThrust); }
	void reset();

};


#endif /* ship_h */
