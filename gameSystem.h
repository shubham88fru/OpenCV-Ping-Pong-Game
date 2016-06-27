#pragma once

#include "Ball.h"
//#include "Bat.h"

#include <string>

class gameSystem
{
public:
	gameSystem();
	void startGame();

private:
	OpencvProcessing _processOverlays;
	Ball _ball;
	Bat _bat;

	int _randomBallDirection;
	int _playerNum=1;
	bool _readyToPlay = false;

	void InitGame();
	double _feedWidth;
	double _feedHeight;
	
	//set the threshold values to default.see the function definition for the values
	void _defaultThreshVals();
	
	//set the thresholdvalues to alredy caliberarted value by directly feeding the hardcoded value
	//while using for the first time call _defaultThreshVals() and not the _hardCodedThreshVals
	//and caliberate to HSV value note them in text document for reference
	//once done comment the _defaultThreshVal,hardcode the HSV values noted in the _hardCodeThreshVals
	//and call it.
	void _trackPlayers();

};

