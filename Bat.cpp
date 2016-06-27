#include "Bat.h"


Bat::Bat()
{
}

void Bat::moveBat(Mat &img, float yCoOrdinatePlayer,float feedHeight)
{
	yCoOrdPlayer1 = yCoOrdinatePlayer;

	if ((yCoOrdinatePlayer >= (_batLength / 2.0)) && (yCoOrdinatePlayer <= (feedHeight - (_batLength / 2.0)))){
	
		pt1Player1 = Point(0, (yCoOrdinatePlayer + (_batLength / 2.0)));
		pt2Player1 = Point(_batWidth, (yCoOrdinatePlayer - (_batLength / 2.0)));
	}
	_newBat.DrawBatPlayer1(img, pt1Player1, pt2Player1);
}

void Bat::moveBat(Mat &img, float yCoOrdinatePlayer, float feedWidth,float feedHeight)
{
	yCoOrdPlayer2 = yCoOrdinatePlayer;

	if ((yCoOrdinatePlayer >= (_batLength / 2.0)) && (yCoOrdinatePlayer <= (feedHeight - (_batLength / 2.0)))){
	
		pt1Player2 = Point(feedWidth, (yCoOrdinatePlayer + (_batLength / 2.0)));
		pt2Player2 = Point((feedWidth - _batWidth), (yCoOrdinatePlayer - (_batLength / 2.0)));

		
	}
	_newBat.DrawBatPlayer2(img, pt1Player2, pt2Player2);
}

int Bat::getBatLength(){

	return _batLength;
}

int Bat::getBatWidth(){

	return _batWidth;
}