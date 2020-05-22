#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0, 0, 0);
	ofSetFrameRate(10);
	Line newLine;
	newLine.setup();
	lines.push_back(newLine);
	Grid newGrid = Grid();
	newGrid.setup();
	grids.push_back(newGrid);
}

//--------------------------------------------------------------

bool shouldRemove(Grid &g) {
	if (!g.isAlive()) {
		return true;
	}
	return false;
}
void ofApp::update() {
	for (int i = 0; i < grids.size(); i++) {
		grids[i].update();
	}
	ofRemove(grids, shouldRemove);
}

void ofApp::draw() {
	for (int i = 0; i < grids.size(); i++) {
		grids[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	if (key == 'c') {
		grids.clear();
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	mouse = { mouseX, mouseY, 0 };
	Grid newGrid = Grid();
	newGrid.setup();
	grids.push_back(newGrid);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	mouse = { mouseX, mouseY, 0 };
	Grid newGrid = Grid();
	newGrid.setup();
	grids.push_back(newGrid);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
