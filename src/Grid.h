#pragma once

#include "ofMain.h"
#include "line.hpp"
class Grid : public ofBaseApp
{
public:
	Grid();
	void setup();
	void update();
	void draw();
	void glitch();
	bool isAlive();
	int lineWidth;
	std::vector <Line> grid;
};