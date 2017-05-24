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
		
    /////////SYNTH//////////
    void audioOut(float * buffer, int bufferSize, int nChannels);
    
    double outputs[2];
    maxiMix mix;
    
    unsigned bufferSize, sampleRate;
    double numKeys = 8;
    
    maxiOsc VCO1[8], VCO2[8], VCO3[8], LFO1[8], LFO2[8];
    maxiFilter VCF[8];
    maxiEnv ADSR[8];
    
    double cSample, freq, VCO1out[8], VCO2out[8], VCO3out[8], LFO1out[8], LFO2out[8], VCFout[8], ADSRout[8];
    
    /////////////VISUALS//////////////
    void branch(float);
    void inverseBranch(float);
    
    float startLength, angle, branchMultiplier;
    double freqDisplay = freq;
    
};
