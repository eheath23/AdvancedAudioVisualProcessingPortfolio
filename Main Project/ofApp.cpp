#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::branch(float length){
    //Function for recursive branch, takes the legnth of the branch as an argument
    
    //draws line
    ofDrawLine(0, 0, 0, -length);
    ofDrawCircle(0, 0, 1);
    
    //translates to the end of the line
    ofTranslate(0, -length);
    
    //if the legnth of the line is greater than five pixels, draw two branches
    if(length > 5){
        ofPushMatrix();
        ofRotate(angle);
        branch(length*branchMultiplier);
        ofPopMatrix();
        
        ofPushMatrix();
        ofRotate(-angle);
        branch(length*branchMultiplier);
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ofApp::setup(){
    //typical audio setup
    sampleRate = 44100;
    bufferSize = 512;
    ofSoundStreamSetup(2, 0, this, sampleRate, bufferSize, 4);
    
    //for each of the ADSR objects, set the attack, decay, sustain, and release
    for (int i=0;i<numKeys;i++) {
        
        ADSR[i].setAttack(200);
        ADSR[i].setDecay(1);
        ADSR[i].setSustain(1);
        ADSR[i].setRelease(1000);
        
    }
    
    ofBackground(0);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //for each of the key objects, map freqDisplay to the startLength and angle of the tree
    for(int i = 0; i < numKeys; i++){
        //startLength = ofMap(mouseY, ofGetHeight(), 0, 0, 100);
        startLength = ofMap(freqDisplay, 0, 1000, 0, 150);;
        angle = ofMap(freqDisplay, 0, 300, 0, 180);
    }
    //increment freqDisplay
    freqDisplay++;
    startLength = 150;
    branchMultiplier = 0.7;
    
//    ofSetColor(ofMap(freqDisplay, 130.81, 261.63, 0, 250), ofMap(freqDisplay, 130.81, 261.63, 0, 20), ofMap(freqDisplay, 130.81, 261.63, 0, 50));
    
    //Draw the first branch
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofPushMatrix();
    branch(startLength);
    ofPopMatrix();
    
    //Draw a second branch rotated by 90 degrees
    ofPushMatrix();
    ofRotate(90);
    branch(startLength);
    ofPopMatrix();
    
    //Draw a third branch rotated by 180 degrees
    ofPushMatrix();
    ofRotate(180);
    branch(startLength);
    ofPopMatrix();
    
    //Draw a fourth branch rotated by 270 degrees
    ofPushMatrix();
    ofRotate(270);
    branch(startLength);
    ofPopMatrix();
    
    //Draw a fifth branch at twice the size
    ofPushMatrix();
    branch(startLength*2);
    ofPopMatrix();
    
    //Draw a sixth branch at twice the size, rotated by 90 degrees
    ofPushMatrix();
    ofRotate(90);
    branch(startLength*2);
    ofPopMatrix();
    
    //Draw a seventh branch at twice the size, rotated by 180 degrees
    ofPushMatrix();
    ofRotate(180);
    branch(startLength*2);
    ofPopMatrix();
    
    //Draw a eighth branch at twice the size, rotated by 270 degrees
    ofPushMatrix();
    ofRotate(270);
    branch(startLength*2);
    ofPopMatrix();
    
    //Draw a circle at the centre of the screen
    ofDrawCircle(0, 0, 10);
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels){
    //for each sample in the buffer
    for(unsigned i = 0; i < bufferSize; i++){
        //for each key
        for (int j = 0; j < numKeys; j++) {
            
            //fill ADSRout with ADSR
            ADSRout[j] = ADSR[j].adsr(1.0, ADSR[j].trigger);
        
            //fill LFO1out with a sine wave at 5Hz
            LFO1out[j] = LFO1[j].sinebuf(5);
        
            //fill VCO1out with a sawtooth wave with a frequency of variable freq
            VCO1out[j] = VCO1[j].saw(freq);
            //fill VCO2out with a square wave, with a frequency of freq*1 add LFO1out
            VCO2out[j] = VCO2[j].square(freq*1.5+LFO1out[j]);
            //fill VCO3out with a sawtooth wave, with a frequency of freq*0.5*LFO2out
            VCO3out[j] = VCO3[j].saw(freq*0.5);
        
            //Filter all of the VCO outputs with a low pass filter, with a cutoff frequency of 1000, and a resonance of 15, and fill VCFout with the result
            VCFout[j] = VCF[j].lores(VCO1out[j] + VCO2out[j] + VCO3out[j] * 0.3, 1000, 15);
        
            //Modulate the output from VCFout by the ADSRout, so that when the Envelope is triggered, the output from the filter will be heard
            cSample += (VCFout[j]*ADSRout[j])/8;
        }
        
        //Standard mixer settings, even mix between left and right
        mix.stereo(cSample, outputs, 0.5);
        
        output[i * nChannels] = outputs[0];
        output[i * nChannels + 1] = outputs[1];
        
        //for each key, turn the envelope off
        for (int j = 0; j < numKeys; j++) {
            ADSR[j].trigger=0;
        }
    }
}


//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    //if the key pressed is a, or s etc. set the frequency to a note from the C major scale, and trigger the envelope
    if(key == 'a'){
        freq = 130.81;
        ADSR[0].trigger = 1;
        freqDisplay = freq;
    }
    if(key == 's'){
        freq = 146.83;
        ADSR[1].trigger = 1;
        freqDisplay = freq;
    }
    if(key == 'd'){
        freq = 164.81;
        ADSR[2].trigger = 1;
        freqDisplay = freq;
    }
    if(key == 'f'){
        freq = 174.61;
        ADSR[3].trigger = 1;
        freqDisplay = freq;
    }
    if(key == 'g'){
        freq = 196.00;
        ADSR[4].trigger = 1;
        freqDisplay = freq;
    }
    if(key == 'h'){
        freq = 220.00;
        ADSR[5].trigger = 1;
        freqDisplay = freq;
    }
    if(key == 'j'){
        freq = 246.94;
        ADSR[6].trigger = 1;
        freqDisplay = freq;
    }
    if(key == 'k'){
        freq = 261.63;
        ADSR[7].trigger = 1;
        freqDisplay = freq;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    //When the key is released, turn the envelope off
    if(key == 'a'){
        ADSR[0].trigger = 0;
    }
    if(key == 's'){
        ADSR[1].trigger = 0;
    }
    if(key == 'd'){
        ADSR[2].trigger = 0;
    }
    if(key == 'f'){
        ADSR[3].trigger = 0;
    }
    if(key == 'g'){
        ADSR[4].trigger = 0;
    }
    if(key == 'h'){
        ADSR[5].trigger = 0;
    }
    if(key == 'j'){
        ADSR[6].trigger = 0;
    }
    if(key == 'k'){
        ADSR[7].trigger = 0;
    }
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
