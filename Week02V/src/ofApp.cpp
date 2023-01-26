#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(30);
    ofSetWindowTitle("openframeworks");
     
    ofBackground(39);
    ofSetColor(239);
    ofEnableDepthTest();
     
    for (int i = 0; i < 2000; i++) {
        float t = rand();
        vector<float> cord = HeartFunction(t, 20);
        float x = cord[0];
        float y = cord[1];
        this->particles.push_back(Particle(x, y));
    }
}

//--------------------------------------------------------------
void ofApp::update(){
    float frame = ofGetFrameNum() / 30.0;
    cout << frame << endl;
    for (Particle& particle : particles) {
        particle.Update(cos(frame));
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
