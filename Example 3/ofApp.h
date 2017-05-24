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

    int bufferSize, sampleRate;
    double currentSample;
    double outputs[2];
    double kickSample, snareSample;
    
    ofxMaxiSample kick, snare, hat;
    maxiMix mix;
    
    maxiOsc osc, osc2;
    
    int currentCount,lastCount,playHead;
    
    int kickPattern[16]={1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,0};
    int snarePattern[16]={0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0};
    int hatPattern[16]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    bool kickTrigger,snareTrigger,hatTrigger;
    
    ofSpherePrimitive plane;
    ofVboMesh deformPlane;
    
    ofLight pointLight;
    
    ofImage myImage;
    
    float amp=0;

};
