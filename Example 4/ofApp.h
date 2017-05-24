#pragma once

#include "ofMain.h"
#include "ofxMaxim.h"


class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y);
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    
    void audioOut(float * output, int bufferSize, int nChannels);
    void audioIn(float * input, int bufferSize, int nChannels);
    
    maxiOsc Osc, Osc2, Osc3, Osc4, Osc5, Osc6, Osc7, Osc8, Osc9, Osc10, lfo, lfo2, lfo3, lfo4;
    
    maxiMix mix;
    
    double outputs[2];
    
    double freq1, freq2, freq3, lfoFreq, lfoFreq2, cSample, cSample1;
    unsigned bufferSize, sampleRate;
    
    float x = 0, y = 0;
    
    float magnify = 300;
    float rotation = 0;
    float radius = 0;
    int elements = 75;
    
    float rotation1 = 7;
    float radius1 = 7;
    int elements1 = 75;
    
};


