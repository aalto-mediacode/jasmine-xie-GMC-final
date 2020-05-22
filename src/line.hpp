#pragma once

#include "ofMain.h"

//class Line : public ofBaseApp
class Line
{
public:

	Line();
	void setup();
	void update();
	void draw();

	int i;
	glm::vec3 start;
	ofPolyline line;
	int stepAxis;
	int stepDir;
	int stepSize;
	int stepMin;
	int stepMax;
	int lifespan;
	int decayRate;

	int mainAlpha;
	int secondaryAlpha;
	int glitchAlpha;
	ofColor mainC;
	ofColor secondaryC;
	ofColor glitchC;
	bool glitched;

	void step(int stepSize);
	void decay(int orig);
	ofPolyline glitch();
};
