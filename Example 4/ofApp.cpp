#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    //standard audio setup, set frequencies too
    sampleRate = 44100;
    bufferSize = 512;
    freq1 = 200;
    freq2 = 400;
    freq3 = 800;
    lfoFreq = 1;
    lfoFreq2 = 4;
    ofSoundStreamSetup(2, 0, this, sampleRate, bufferSize, 4);
    
    ofBackground(200);
    ofSetLineWidth(0.2);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //increase x and y
    x+=0.5;
    y+=0.4;
    
    //when x and y reach 1000, set them to 0
    if(x > 10000){
        x = 0;
    }
    if(y > 10000){
        y = 0;
    }
    
    ofBackground(ofRandom(10, 15));
    
    //calculate radius and rotation using x and y, spacing is 360 degrees divided by the number elements
    radius = (float) x / 1000;
    rotation = (float) y;
    float spacing = TWO_PI/elements;
    
    //calculate radius1 and rotation1 using x and y, spacing is 360 degrees divided by the number elements
    radius1 = (float) x / 750;
    rotation1 = (float) y;
    float spacing1 = TWO_PI/elements1;
    
    //translate to the centre
    ofTranslate(ofGetWidth()*0.5, ofGetHeight()*0.5);
    
    //Nested "Differential Dyanimics" style calculations
    for(int i = 0; i < elements; i++){
        for(int j = 0; j < elements1; j++){
        ofSetColor(ofRandom(200, 215));
        ofPushMatrix();
        //rotate by even spacing of each element, multiplied by the element number i, multiplied by the rotation amount
        ofRotate(spacing*i*rotation);
        //Translate by sin of even spacing of each element, multiplied by the element number i, multiplied by the radius, multiplied by the magnification amount, and cos of the second spacing amount, multiplied by the element number j, multiplied by radius1
        ofTranslate(sin(spacing*i*radius)*magnify, cos(spacing1*j*radius1));
        //draw a line from 5, 5, to elemenent i multiplied by the second rotation amount, and element i mupltiplied by the second radius value
        ofDrawLine(5, 5, i*rotation1, i*radius1);
        ofPopMatrix();
        
        }
    }
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels) {
    for(unsigned i = 0; i < bufferSize; i++){
        
        //Osc = sine wave frequency modulated by Osc 2, a square with frequency of radius, mulitiplied by sine lfo with frequency of radius 1
        //Osc2 = square wave frequency modulated by Osc 3, a phasor
        //Osc + Osc2, amplitude modulated by Osc 4, a square wave, frequency modulated by Osc 5, a phasor
        //Amplitude modulated by lfo 2, a sine wave
        cSample = ((Osc.sinebuf(Osc2.square(radius)) * lfo.sinewave(radius1)) + (Osc2.square(Osc3.phasor(0.002, 20, 800))* (Osc4.square(Osc5.phasor(0.005, 300, 900))))/2 * lfo2.sinewave(lfoFreq2));
        
        //Very similar to the previous sample, but with slight changes to the phasors, causing the 2 samples to be slightly out of phase
        cSample1 = ((Osc6.sinebuf(Osc7.square(radius)) * lfo3.sinewave(radius1)) + (Osc7.square(Osc8.phasor(0.003, 20, 800))* (Osc9.square(Osc10.phasor(0.006, 300, 900))))/2 * lfo4.sinewave(lfoFreq2));
        
        //pan cSample and cSample1 left and right
        output[i * nChannels] = cSample;
        output[i * nChannels + 1] = cSample1;
    }

}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){
    
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
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
