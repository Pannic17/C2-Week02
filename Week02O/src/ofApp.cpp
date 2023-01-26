#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    ofSetWindowTitle("openframeworks");
     
    ofBackground(39);
    ofSetColor(239);
    ofEnableDepthTest();
     
    for (int i = 0; i < 128; i++) {
        this->particles.push_back(Particle());
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    for (Particle& particle : particles) {
        particle.Upate();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    this->cam.begin();
    ofRotateY(ofGetFrameNum() * 0.5);
     
    for (Particle& particle : particles) {
        particle.Draw();
    }
     
    this->cam.end();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}


Particle::Particle() {
 
    this->depth = ofGetWidth() > ofGetHeight() ? ofGetWidth() : ofGetHeight();
 
    int x = (int)(ofRandom(ofGetWidth()) / 20) * 20;
    int y = (int)(ofRandom(ofGetHeight()) / 20) * 20;
    int z = (int)(ofRandom(this->depth) / 20) * 20;
    this->location = ofPoint(x, y, z);
 
    this->directions[0] = ofPoint(1, 0, 0);
    this->directions[1] = ofPoint(-1, 0, 0);
    this->directions[2] = ofPoint(0, 1, 0);
    this->directions[3] = ofPoint(0, -1, 0);
    this->directions[4] = ofPoint(0, 0, 1);
    this->directions[5] = ofPoint(0, 0, -1);
}
 
Particle::~Particle(){
 
}
 
void Particle::Upate() {
 
    if (ofGetFrameNum() % 20 == 0) {
 
        int r = ofRandom(6);
        this->direction = this->directions[r];
 
        if (this->location.x < 0) { this->direction = this->directions[0]; }
        else if (this->location.x > ofGetWidth()) { this->direction = this->directions[1]; }
 
        if (this->location.y < 0) { this->direction = this->directions[2]; }
        else if (this->location.y > ofGetHeight()) { this->direction = this->directions[3]; }
 
        if (this->location.z < 0) { this->direction = this->directions[4]; }
        else if (this->direction.z > this->depth) { this->direction = this->directions[5]; }
    }
 
    this->location += this->direction * 2;
 
    this->logs.push_front(location - ofPoint(ofGetWidth() * 0.5, ofGetHeight() * 0.5, this->depth * 0.5));
    while (this->logs.size() > 90) { this->logs.pop_back(); }
}
 
void Particle::Draw() {
 
    ofFill();
    ofDrawSphere(this->logs.front(), 3);
 
    ofNoFill();
    ofBeginShape();
    for (ofPoint& log : this->logs) {
 
        ofVertex(log);
    }
    ofEndShape();
}
