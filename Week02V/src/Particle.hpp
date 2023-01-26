//
//  Particle.hpp
//  Week02V
//
//  Created by Nicholas Pan on 2023/1/25.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <stdio.h>
#include "ofMain.h"

class Particle{
public:
    Particle(float x, float y);
//    ~Particle();
    void Update(float p);
    void Draw();
    
    void GenerateVector();
    vector<ofPoint> CalculatePosition(float p);
 
private:
    float angle[5];
    int color[3];
    
    ofPoint position;
    vector<ofPoint> points;
};

vector<float> HeartFunction(float t, int size);

#endif /* Particle_hpp */
