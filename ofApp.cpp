#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetWindowTitle("openFrameworks");
	ofSetFrameRate(25);

	ofBackground(39);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWindowSize() * 0.5);

	auto noise_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));
	for (int x = -270; x <= 270; x += 60) {

		for (int y = -270; y <= 270; y += 60) {

			ofPushMatrix();
			ofTranslate(x, y);

			auto distance = glm::length(glm::vec2(x, y));

			auto x_value = ofNoise(noise_seed.x, x * 0.0025, y * 0.0025, ofGetFrameNum() * 0.015);
			auto y_value = ofNoise(noise_seed.y, x * 0.0025, y * 0.0025, ofGetFrameNum() * 0.015);
			auto z_value = ofNoise(noise_seed.z, x * 0.0025, y * 0.0025, ofGetFrameNum() * 0.015);

			auto x_deg = x_value < 0.35 ? ofMap(x_value, 0, 0.35, -360, 0) : x_value > 0.75 ? ofMap(x_value, 0.75, 1, 0, 360) : 0;
			auto y_deg = y_value < 0.35 ? ofMap(y_value, 0, 0.35, -360, 0) : y_value > 0.75 ? ofMap(y_value, 0.75, 1, 0, 360) : 0;
			auto z_deg = z_value < 0.35 ? ofMap(z_value, 0, 0.35, -360, 0) : z_value > 0.75 ? ofMap(z_value, 0.75, 1, 0, 360) : 0;

			ofRotateZ(z_deg);
			ofRotateY(y_deg);
			ofRotateX(x_deg);

			ofSetColor(0);

			ofFill();
			ofDrawBox(15);

			ofNoFill();
			ofDrawBox(35);

			ofSetColor(255);

			ofDrawBox(15);

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}