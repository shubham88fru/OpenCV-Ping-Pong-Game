#include "gameSystem.h"
#include <iostream>

using namespace std;

gameSystem::gameSystem()
{
}

void gameSystem::InitGame()
{
	//initialize the initial position of the ball to center of the screen
	_ball.initialPosX = _feedWidth / 2;
	_ball.initialPosY = _feedHeight / 2;

	//_defaultThreshVals();
	
	cout << "********************Welecome to the Your PingPong Game*********************\n\n";
	
	//generate any random direction for moving the ball at the start of the game
	_ball.randomDirectionGenerator();

}

void gameSystem::startGame()
{
	VideoCapture Cap;

	//start capturing and check if we succeeded
	Cap.open(0);
	if (!Cap.isOpened()){
		cerr << "Couldn't detect the webcam!, make sure you have attached one!\n\n";
	}

	//get the frame width and height
	_feedWidth = Cap.get(CV_CAP_PROP_FRAME_WIDTH);
	_feedHeight = Cap.get(CV_CAP_PROP_FRAME_HEIGHT);

	//initialize the game by performing the initial setups like 
	//generating the random direction for monvement of the ball 
	//setting the ball and paddles to their initial positions etc. 
	InitGame();

	namedWindow("PingPongGame", 1);

	while (1){

		//grab the frames
		Cap >> _processOverlays.CameraFeed;

		waitKey(10);

		_trackPlayers();

		//detect the players
		//_processOverlays.detectPlayers(_processOverlays.CameraFeed);
		
		//check if the players are ready to play
		if (waitKey(10) == 'p'){
			_readyToPlay = true;
		}

		//start the game only when the players are ready i.e. both of them have been detected
		if (_readyToPlay==true){
		
			//handle the movement of the ball
			_ball.move(_ball.initialPosX, _ball.initialPosY, _processOverlays.CameraFeed,_bat);

			//handle the movement of the paddle
			if (_playerNum == 1)
				_bat.moveBat(_processOverlays.CameraFeed, _processOverlays.centerYplayer1,_feedHeight);
			else
				_bat.moveBat(_processOverlays.CameraFeed, _processOverlays.centerYplayer2, _feedWidth,_feedHeight);

			//overlay the player names
			//_processOverlays.textOverlay(_processOverlays.CameraFeed);
		}
		imshow("PingPongGame", _processOverlays.CameraFeed);
	}


}

void gameSystem::_defaultThreshVals()
{

	//---set the low & high Values
	_processOverlays.lowH = 0;
	_processOverlays.highH = 179;

	_processOverlays.lowS = 0;
	_processOverlays.highS = 255;

	_processOverlays.lowV = 0;
	_processOverlays.highV = 255;
}

void gameSystem::_trackPlayers()
{
	if (_playerNum == 1){
		Scalar HSVmin = Scalar(93, 160, 235);
		Scalar HSVmax = Scalar(179, 255, 255);
		_processOverlays.detectPlayers(_processOverlays.CameraFeed, _playerNum, HSVmin, HSVmax);
		_playerNum = 2;
	}
	else{
		Scalar HSVmin = Scalar(126, 0, 255);
		Scalar HSVmax = Scalar(179, 164, 255);
		_processOverlays.detectPlayers(_processOverlays.CameraFeed, _playerNum, HSVmin, HSVmax);
		_playerNum = 1;
	}
	

}