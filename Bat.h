#pragma once

#include "OpencvProcessing.h"

class Bat
{
public:
	Bat();
	Point pt1Player1,pt2Player1;
	Point pt1Player2,pt2Player2;

	float yCoOrdPlayer1, yCoOrdPlayer2;

	void moveBat(Mat &img, float yCoOrdinatePlayer, float feedHeight);
	void moveBat(Mat &img, float yCoOrdinatePlayer, float feedWidth, float feedHeight);
	
	int getBatLength();
	int getBatWidth();
private:
	//width of the bat & lenght of the bat
	int _batWidth = 10;
	int _batLength = 70;

	OpencvProcessing _newBat;
};

