#include "Line.hpp"
Line::Line() {

}

void Line::setup() {
	glm::vec3 start = { ofGetMouseX() , ofGetMouseY(), 0 };
	line;
	line.addVertex(start);
	stepMin = 75;
	stepMax = 125;
	stepAxis;
	stepDir;
	stepSize = ofRandom(stepMin, stepMax);
	lifespan = 255;
	decayRate = ofRandom(5, 10);
	mainAlpha = lifespan;
	secondaryAlpha = lifespan - 45;
	glitchAlpha = lifespan + 50;

	int colorScheme = ofRandom(-4, 9);
	if (colorScheme > 2) {
		mainC = ofColor(0, 0, 255, mainAlpha);
		secondaryC = ofColor(255, 0, 255, secondaryAlpha);
	}
	else if (colorScheme > -1) {
		mainC = ofColor(255, 0, 0, mainAlpha);
		secondaryC = ofColor(255, 255, 0, secondaryAlpha);
	}
	else {
		mainC = ofColor(0, 255, 0, mainAlpha);
		secondaryC = ofColor(0, 255, 255, secondaryAlpha);
	}
	glitchC = ofColor(255, 255, 255, glitchAlpha);
	glitched = false;
}

void Line::update() {
	//update the line with a new vertex
	stepSize = ofRandom(stepMin, stepMax);
	//adds a new vertex
	step(stepSize);
	//decays the colors
	lifespan = MAX(0, lifespan - decayRate);
	decay(lifespan);
}

void Line::step(int stepSize) {
	int prevStepAxis = stepAxis;
	int prevDir = stepDir; 
	stepAxis = glm::round(ofRandom(0, 1));
	stepDir = glm::round(ofRandom(0, 1));
	if (stepDir == 0) {
		stepDir = -1;
	}
	glm::vec3 stepV;
	//ensures that we don't ever go backwards on the same line
	if (prevStepAxis == stepAxis && prevDir != stepDir) {
		stepDir *= -1;
	}
	//moves on X-axis
	if (stepAxis == 0) {
		stepV = { stepDir*stepSize, 0, 0 };
	}
	//moves on Y-axis
	else {
		stepV = { 0, stepDir*stepSize,0 };
	}
	int lastIndex = line.size() - 1;
	glm::vec3 newPoint = line[lastIndex] + stepV;
	line.addVertex(newPoint);
}

void Line::decay(int lifespan) {
	mainAlpha = lifespan;
	secondaryAlpha = MAX(0, lifespan - 45);
	glitchAlpha = MAX(0, lifespan - 10);
	mainC = ofColor(mainC, mainAlpha);
	secondaryC = ofColor(secondaryC, secondaryAlpha);
	glitchC = ofColor(glitchC, glitchAlpha);
}

ofPolyline Line::glitch() {
	ofPolyline glitchLine = line;
	glitched = false;
	int base = ofRandom(0, ofGetWindowWidth() - 300);
	for (int i = 0; i < glitchLine.size(); i++) {
		if (glitchLine[i].x > base && glitchLine[i].x < base + 25) {
			glitchLine[i] += {125, 0, 0};
			glitched = true;
		}
	}
	return glitchLine;
}

void Line::draw() {
	ofPushMatrix();
	ofTranslate(10, 6);
	int chance = ofRandom(0, 15);
	ofPolyline glitchedLine = glitch();
	if (glitched && chance < 12) {
		ofSetColor(secondaryC);
		glitchedLine.draw();
		ofTranslate(stepSize / 8, stepSize / 8);
		ofSetColor(glitchC);
		glitchedLine.draw();
		ofPopMatrix();
		ofSetColor(mainC);
		glitchedLine.draw();
	}
	else {
		ofSetColor(secondaryC);
		line.draw();
		ofPopMatrix();
		ofSetColor(mainC);
		line.draw();
	}
}