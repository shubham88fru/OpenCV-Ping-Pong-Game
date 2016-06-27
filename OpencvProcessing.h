#pragma once

#include <string>
#include <vector>
//#include <sstream>

//opencv header files
#include<opencv\cv.h>
#include<opencv2\opencv.hpp>

using namespace cv;

class OpencvProcessing
{
public:
	
	OpencvProcessing();
	
	Mat CameraFeed;
	
	//points to write the scores
	Point score1point = Point(80, 45);
	Point score2point = Point(480, 45);
	
	//points to draw the paddle1
	//Point pt1 = Point(0,)
	
	//Radius of the ball to be drawn
	int ballRadius = 6;

	//to calculate the Y coordinates of the paddle
	float centerYplayer1=0;
	float centerYplayer2=0;

	//setup the the trackbar
	//---set the low & high Values
	int lowH;
	int highH;

	int lowS;
	int highS;

	int lowV;
	int highV;
	
	int Score1 = 0, Score2 = 0;

	//draw the ball
	void DrawBall(Point center,Mat &img);
	//draw the paddles
	void DrawBatPlayer1(Mat &img,Point pt1,Point pt2);
	//draw the paddles
	void DrawBatPlayer2(Mat &img, Point pt1, Point pt2);
	//overlay text like name of the players
	void textOverlay(Mat &img,int &score1,int &score2);
	//detect the palyers
	void detectPlayers(Mat &img, int playerNum, Scalar HSVmin, Scalar HSVmax);

private:
	bool _isAlreadyThreshed = false;
	bool _showContour = false;
	Mat _hsvImg;
	Mat _threshHoldImg;
	Mat _equalizedHist;

	void _threshFeed(int playerNum, Scalar HSVmin, Scalar HSVmax);
	void _morphOps(Mat &_threshHoldImg);
	void _findContours(Mat &img, int playerNum);
	
};

