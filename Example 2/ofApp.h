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
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void audioOut(float * buffer, int bufferSize, int nChannels);
    
    double outputs[2];
    maxiMix mix;
    
    unsigned bufferSize, sampleRate;
    
    maxiOsc VCO1, VCO2, VCO3, LFO1, LFO2;
    maxiFilter VCF;
    maxiEnv ADSR;
    
    double cSample, freq, VCO1out, VCO2out, VCO3out, LFO1out, LFO2out, VCFout, ADSRout;
    
    float magnify = 300; // This is how big we want the rose to be.
    float rotation = 0; // rotation : this is basically how far round the circle we are going to go
    float radius = 0; // radius : this is basically how far from the origin we are.
    int elements = 256;// This is the number of points and lines we will calculate at once. 1000 is alot actually.

		
};
