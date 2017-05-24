#include "ofApp.h"
//This uses code from Mick Grierson's Advanced Audio-Visual Processing Week 7 Examples

//--------------------------------------------------------------
void ofApp::setup(){
    //Standard audio setup
    sampleRate = 44100;
    bufferSize = 512;
    ofSoundStreamSetup(2, 0, this, sampleRate, bufferSize, 4);
    
    ofBackground(0);
    
    //Set the attack, decay, sustain and release of the envelope, ADSR
    ADSR.setAttack(1000);
    ADSR.setDecay(3);
    ADSR.setSustain(1);
    ADSR.setRelease(200);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    //set the radius to the map of the frequency between 1 and 2
    radius = (float) ofMap(freq, 100, 300, 1, 2);
    //rotation is the mapping of the frequency between 1 and 5, add rotation
    rotation += (float) ofMap(freq, 100, 300, 1, 5);
    //spacing is equal to 360 degrees divided by the number of elements
    float spacing = TWO_PI/elements;
    //translate to the centre of the screen
    ofTranslate(ofGetWidth()*0.5,ofGetHeight()*0.5);
    
    ofNoFill();
    //for the number of elements
    for (int i = 0; i < elements; i++) {
        //set the colour to white
        ofSetColor(255);
        
        //These circles are all drawn at the same pixel coordinates, but the movement is created by rotating and translating each one
        ofPushMatrix();
        //rotate by spacing * i * rotation
        ofRotate(spacing*i*rotation);
        //translate by sin of spacing*i*radius, multiplied by magnifucation amount
        ofTranslate(sin(spacing*i*radius)*magnify, 0);
        ofCircle(0, 0, i);
        ofPopMatrix();
    }
}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels){
    for(unsigned i = 0; i < bufferSize; i++){
        //fill ADSRout with ADSR
        ADSRout = ADSR.adsr(1.0, ADSR.trigger);
        
        //fill LFO1out with a sine wave at 5Hz
        LFO1out = LFO1.sinebuf(5);
        
        //fill VCO1out with a sawtooth wave with a frequency of variable freq
        VCO1out = VCO1.saw(freq);
        
        //fill VCO2out with a square wave, with a frequency of freq*1 add LFO1out
        VCO2out = VCO2.square(freq*1.5+LFO1out);
        
        //fill VCO3out with a sawtooth wave, with a frequency of freq*0.5*LFO2out
        VCO3out = VCO3.saw(freq*0.5);
        
        //Filter all of the VCO outputs with a low pass filter, with a cutoff frequency of between 0 and 1000, controlled by the mouse Y position, and a resonance of 15, and fill VCFout with the result
        VCFout = VCF.lores(VCO1out + VCO2out + VCO3out * 0.3, ofMap(mouseY, ofGetHeight(), 0, 0, 1000), 15);
        
        //Modulate the output from VCFout by the ADSRout, so that when the Envelope is triggered, the output from the filter will be heard
        cSample = VCFout*ADSRout;
        
        //Standard mixer settings, even mix between left and right
        mix.stereo(cSample, outputs, 0.5);
        
        output[i * nChannels] = outputs[0];
        output[i * nChannels + 1] = outputs[1];
    }
    
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
    //Frequency is controlled by the mouse X position
    freq = ofMap(mouseX, 0, ofGetWidth(), 100, 300);
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    //When the mouse is pressed, trigger the envelope
    ADSR.trigger = 1;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    //When the mouse is released, release the envelope
    ADSR.trigger = 0;
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
