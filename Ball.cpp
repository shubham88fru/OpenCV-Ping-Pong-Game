#include "Ball.h"
#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;
Ball::Ball()
{
}

//move the function in the randomly generated direction
void Ball::move(double &posX, double &posY, Mat &Img,Bat bat)
{
	//get the framewidth and height at the begining of the game
	static double frameWidth = 2 * posX;
	static double frameHeight = 2 * posY;

	_bat = bat;


	switch (direction){
	case 1:
		posY -= 2;
		posX += 3;
		break;
		
	case 2:
		posY -= 2;
		posX -= 3;
		break;

	case 3:
		posY += 2;
		posX += 3;
		break;

	case 4:
		posY += 2;
		posX -= 3;
		break;
	}
	//detect the collision of the ball with the walls/paddle
	_detectCollision(posX, posY, direction, frameWidth, frameHeight);

	_processBall.DrawBall(Point(posX, posY),Img);
	_processBall.textOverlay(Img, _processBall.Score1, _processBall.Score2);
}

//generate a random direction to start the ball movement
void Ball::randomDirectionGenerator()
{
	srand(time(NULL));
	direction= rand() % 4 + 1;
}

//detect the collision of ball
void Ball::_detectCollision(double &posX, double &posY, int &direction,double frameWidth,double frameHeight)
{
	if ((posY == _processBall.ballRadius) &&(direction==UPRIGHT||direction==UPLEFT) ){
		
			switch (direction){
			case 1:
				direction = DOWNRIGHT;
				break;

			case 2:
				direction = DOWNLEFT;
				break;
			}
		
	}
	else if ((posY == (frameHeight - _processBall.ballRadius)) && (direction == DOWNRIGHT || direction == DOWNLEFT)){
		
			switch (direction){
			case 3:
				direction = UPRIGHT;
				break;

			case 4:
				direction = UPLEFT;
				break;
			}
		
	}
	
	//detect the collision of the ball with th bat
	if ((posX <= (_processBall.ballRadius + _bat.getBatWidth())) && (direction == UPLEFT || direction == DOWNLEFT)){

		if ((posY >= (_bat.yCoOrdPlayer1 - (_bat.getBatLength() / 2))) && (posY <= (_bat.yCoOrdPlayer1 + (_bat.getBatLength() / 2)))){
		
			switch (direction){
						case 2:
							direction = UPRIGHT;
							break;

						case 4:
							direction = DOWNRIGHT;
							break;
				
			}
			_processBall.Score1++;
		}
		
	}

	if ((posX >= ((frameWidth)-(_processBall.ballRadius + _bat.getBatWidth()))) && (direction == DOWNRIGHT || direction == UPRIGHT)){

		if ((posY >= (_bat.yCoOrdPlayer2 - (_bat.getBatLength() / 2))) && (posY <= (_bat.yCoOrdPlayer2 + (_bat.getBatLength() / 2)))){

			switch (direction){
						case 1:
							direction = UPLEFT;
							break;

						case 3:
							direction = DOWNLEFT;
							break;

			}
			_processBall.Score2++;
		}
	}
	//if ((posX == _processBall.ballRadius) && (direction == UPLEFT || direction == DOWNLEFT)){
	//	
	//		switch (direction){
	//		case 2:
	//			direction = UPRIGHT;
	//			break;

	//		case 4:
	//			direction = DOWNRIGHT;
	//			break;
	//		}
	//
	//}
	//else if ((posX >= (frameWidth - _processBall.ballRadius)) && (direction == DOWNRIGHT || direction == UPRIGHT)){
	//	
	//		switch (direction){
	//		case 1:
	//			direction = UPLEFT;
	//			break;

	//		case 3:
	//			direction = DOWNLEFT;
	//			break;
	//		}

	//}

}