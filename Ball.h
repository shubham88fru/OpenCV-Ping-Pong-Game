#pragma once

#include "Bat.h"

enum Direction {UPRIGHT=1,UPLEFT=2,DOWNRIGHT=3,DOWNLEFT=4};

class Ball
{
public:


	Ball();

	//store the previous postion of the ball
	double initialPosX, initialPosY;
	//the direction in which the all moves
	int direction;
	
	
	

	void move(double &posX, double &PosY, Mat &Img,Bat bat);
	void randomDirectionGenerator();

private:

	//OpencvProcessing instance to acces the draw function
	OpencvProcessing _processBall;
	Bat	_bat;

	//detect collision
	void  _detectCollision(double &posX,double &posY,int &randomDirection,double frameWidth,double frameHeight);
	//void _detectCollisionWithBat();
};

