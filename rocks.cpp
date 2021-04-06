#include "rocks.h"
#include "flyingObject.h"



//Rock***************************************

Rock :: Rock()
{
	
	//set angle of trajectory
	setAngle(random(0, 360));
	type = "Rock";
	setRotation(0);
	// launch asteroid
	fire(getPoint(), getAngle(), LARGE_ROCK_SPEED);
}


void Rock::setRandomPos()
{
	Point newPoint;
	newPoint.setX(random(-200, 200));
	newPoint.setY(random(-200, 200));
	setPoint(newPoint);
}




//Small*************************************
Smaasteroid::Smaasteroid()
{
	setRadius(SMALL_ROCK_SIZE);
	spin = SMALL_ROCK_SPIN;
	type = "SmaAsteroid";
	
}





// Medium***********************************
Medasteroid::Medasteroid()
{
	setRadius(MEDIUM_ROCK_SIZE);
	spin = MEDIUM_ROCK_SPIN;
	type = "MedAsteroid";
	
}




//Large**************************************
Lrgasteroid::Lrgasteroid()
{
	setRadius(LARGE_ROCK_SIZE);
	spin = LARGE_ROCK_SPIN;
	type = "LrgAsteroid";

	//set position
	setRandomPos();
	
 }



