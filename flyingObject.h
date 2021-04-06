#ifndef flyingObject_h
#define flyingObject_h

#include "point.h"
#include "velocity.h"
#include "uiDraw.h"


// Put your FlyingObject class here
class FlyingObject
{
protected:
	Velocity velocity;
	Point point;
	bool alive;
	float angle;
	float radius;





public:

	//getters
	Point getPoint() const { return point; }
	Velocity getVelocity() const { return velocity;  }
	float getAngle() { return angle; }
	bool isAlive() const { return alive; }
	float getRadius() { return radius; }

	//setters
	void setAlive(bool alive) { this->alive = alive; }
	void setPoint(const Point& point) { this->point = point; }
	void setVelocity(const Velocity& velocity) { this->velocity = velocity; }
	void setAngle(const float input) { this->angle = input; }
	void setRadius(float input) { this->radius = input; }

	//action methods
	void kill() { alive = false; }
	void fire(Point point, float angle, float speed);
	void wrap();
	
	


	//virtual methods
	virtual void advance();
	virtual void draw() {};

	

};



#endif /* flyingObject_h */
