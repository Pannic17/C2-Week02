//
//  Particle.cpp
//  Week02V
//
//  Created by Nicholas Pan on 2023/1/25.
//

#include "Particle.hpp"
Particle::Particle(float x, float y) {
    this->position = ofPoint(x, y, 0);
    GenerateVector();
}

void Particle::GenerateVector() {
    for (int i = 0; i < 5; i++) {
        angle[i] = rand() * 360;
    }
}

vector<ofPoint> Particle::CalculatePosition(float p) {
    vector<ofPoint> ps;
    for (int i = 0; i < 5; i++) {
        float x = position.x + cos(angle[i]) * p * 20;
        float y = position.y;
        float z = position.z + sin(angle[i]) * p * 20;
        ps.push_back(ofPoint(x, y, z));
    }
    return ps;
}

void Particle::Update(float p) {
    this->points = CalculatePosition(p);
}

void Particle::Draw() {
//    ofFill();
//    ofDrawSphere(this->position, 3);
//    ofNoFill();
    
    for (int i = 0; i < 5; i++) {
        ofSetColor(255, 55, 55);
        ofFill();
        ofDrawSphere(this->points[i], 2);
        ofNoFill();
    }
}


vector<float> HeartFunction(float t, int size) {
//    w = abs(u)
//    p = w*sqrt(w/(1 + w))
//
//    x = p*sin(u)
//    y = (p*cos(u) + 1)*0.9
    
    float x = 16 * (pow(sin(t), 3)) * size;
    float y = (13*cos(t) - 5*cos(2*t) - 2*cos(3*t) - cos(4*t)) * size;
    
    vector<float> cord = {x, y};
    return cord;
//    let x = 16*(Math.sin(t) ** 3) * size;
//    let y = - (13*Math.cos(t) - 5*Math.cos(2*t) - 2*Math.cos(3*t) - Math.cos(4*t)) * size;
}
