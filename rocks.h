#ifndef rocks_h
#define rocks_h

#include "uiDraw.h"
#include "flyingObject.h"

#define LARGE_ROCK_SIZE 16
#define MEDIUM_ROCK_SIZE 8
#define SMALL_ROCK_SIZE 4

#define LARGE_ROCK_SPIN 2
#define MEDIUM_ROCK_SPIN 5
#define SMALL_ROCK_SPIN 10

#define LARGE_ROCK_SPEED 1
#define MEDIUM_ROCK_SPEED 1
#define SMALL_ROCK_SPEED 1



// Define the following classes here:
//   Rock
//   BigRock
//   MediumRock
//   SmallRock

class Rock : public FlyingObject
{
protected:
	float rotation;
	int spin;
	string type;

public:
	Rock();
	

	float getRotation() { return rotation; }
	string getType() { return type; }
	

	void setRotation(float input) { this->rotation = input; }
	void rotate() { setRotation(getRotation() + spin); }
	void setRandomPos();
	

	
	
};



	class Smaasteroid : public Rock
	{
	public:
		Smaasteroid();
		void draw() { drawSmallAsteroid(getPoint(), getRotation()); };
		void breakUp() { float PaceHolder = 0; }
	};

	class Medasteroid : public Rock 
	{
	public:
		Medasteroid();
		void draw() { drawMediumAsteroid(getPoint(), getRotation()); };
		void breakUp() { float PaceHolder = 0; }
	};


	class Lrgasteroid : public Rock
	{
	private:


	public:
		Lrgasteroid();
		void draw() { drawLargeAsteroid(getPoint(), getRotation()); };
		//void rotate();
		void breakUp() { float PaceHolder = 0; }
		
		
		
	};


#endif /* rocks_h */
