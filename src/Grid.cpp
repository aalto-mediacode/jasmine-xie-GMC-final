#include "Grid.h"
Grid::Grid() {

}
void Grid::setup() {
	lineWidth = ofRandom(1, 15);
	int numLines = ofRandom(2, 5);
	for (int i = 0; i < numLines; i++) {
		Line newLine = Line();
		newLine.setup();
		grid.push_back(newLine);
	}
}

void Grid::update() {
	for (int i = 0; i < grid.size(); i++) {
		grid[i].update();
	}
}

void Grid::glitch() {

}

bool Grid::isAlive() {
	if (grid[0].lifespan == 0) {
		return false;
	}
	return true;
}
void Grid::draw() {
	for (int i = 0; i < grid.size(); i++) {
		ofSetLineWidth(lineWidth);
		grid[i].draw();
	}
}