#include "ship.h"

// Put your ship methods here

void Ship::turnRight()
{
	direction = direction - ROTATE_AMOUNT;


}


void Ship::turnleft()
{
	direction = direction + ROTATE_AMOUNT;
}


void Ship::thurst()
{

	fire(point, direction + 90);
}

void Ship::advance()
{
	point.addX(velocity.getDx());
	point.addY(velocity.getDy());
}

void Ship::fire(Point point, float angle)
{
	speed = 0.5;

	//float x = velocity.getDx();
	//float y = velocity.getDy();

	//float newX = speed * (-cos(3.141592 / 180.0 * angle)) * -1 ;
	//float newY = speed * (speed * (sin(3.141592 / 180.0 * angle)));

	//velocity.setDx(newX -x);
	//velocity.setDy(newY - y);
	
	this->velocity.setDx(this->velocity.getDx() + (speed * (-cos(3.141592 / 180.0 * angle))*-1) );
	this->velocity.setDy(this->velocity.getDy() + (speed * (sin(3.141592 / 180.0 * angle))) );
}


void Ship :: reset() {
	setAlive(true);
	point.setX(0);
	point.setY(0);
	velocity.setDx(0);
	velocity.setDy(0);
	direction = 0;
}