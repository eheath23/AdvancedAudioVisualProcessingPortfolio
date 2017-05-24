#include "ofApp.h"
//The samples used do not belong to me, I do not own the rights, but I'm not sure who does

//--------------------------------------------------------------
void ofApp::setup(){
    //standard audio setup
    sampleRate = 44100;
    bufferSize = 512;
    ofBackground(0);
    ofSoundStreamSetup(2, 0 , this, sampleRate, bufferSize, 4);
    
    //load the samples to kick, snare and hat
    kick.load(ofToDataPath("BKTreasury-choir1.wav"));
    snare.load(ofToDataPath("BWMTGLove-horns2.wav"));
    hat.load(ofToDataPath("Hat.wav"));
    
    ofSetVerticalSync(true);
    ofBackground(0);
    
    plane.set(200, 200);
    
    plane.setResolution(100);
    plane.setPosition(ofGetWidth()*0.5, ofGetHeight()*0.5, 0);
    
    ofSetSmoothLighting(true);
    pointLight.setDiffuseColor( ofFloatColor(1, 1, 1) );
    pointLight.setSpecularColor( ofFloatColor(1, 1, 1));
    pointLight.setAreaLight(500, 500);
    
    myImage.load("IMG.JPG");
    myImage.getTexture().setTextureWrap( GL_REPEAT, GL_REPEAT );

}

//--------------------------------------------------------------
void ofApp::update(){
    plane.rotate(1,0.2,0.5,0);

}

//--------------------------------------------------------------
void ofApp::audioOut(float * output, int bufferSize, int nChannels){
    for(int i = 0; i < bufferSize; i++){
        
//        currentCount=(int)osc.square(200);
//        
//        
//        if (lastCount!=currentCount) {
//            
//            kickTrigger=kickPattern[playHead%8];
//            snareTrigger=snarePattern[playHead%8];
//            hatTrigger=hatPattern[playHead%8];
//            
//            playHead++;
//            lastCount=0;
//        }
//        
        if (kickTrigger) {
            kickSample = kick.play(osc.phasor(0.1, 0, 400));
        }
        if (snareTrigger) {
            snareSample = snare.play(osc2.phasor(0.1, 0, 400));
        }
//        if (hatTrigger==1) {
//            hat.trigger();
//        }
        
//        currentSample = kick.playOnce() + snare.playOnce() + hat.playOnce();

        currentSample = kickSample + snareSample;

        
        mix.stereo(currentSample, outputs, 0.5);
        
        output[i * nChannels] = outputs[0];
        output[i * nChannels + 1] = outputs[1];
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableDepthTest();
    
    ofEnableLighting();
    pointLight.enable();
    
    myImage.getTexture().bind();
    plane.mapTexCoordsFromTexture( myImage.getTexture() );
    
    deformPlane = plane.getMesh();
    
    ofVec3f vertexValue;
    
    for(int i = 0; i < deformPlane.getNumIndices(); i++ ) {
        amp = 0.0000001; // updates slowing
        
        int vertexIndex = deformPlane.getIndex(i);
        
        vertexValue = deformPlane.getVertex(vertexIndex);
        
        float er = cos(sin(osc.phasor(0.1, 0, 1000)*amp*i));
        float ery = cos(cos(osc2.phasor(0.1, 0, 1000)*amp*i));
        
        vertexValue.x *= er;
        vertexValue.y *= ery;
        vertexValue.z *= er*ery;
        
        deformPlane.setVertex( vertexIndex, vertexValue );
        
    }
    
    plane.transformGL();
    deformPlane.draw();
    plane.restoreTransformGL();
    myImage.getTexture().unbind();
    ofDisableDepthTest();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if(key == 'a'){
        kickTrigger = true;
    }
    if(key == 's'){
        snareTrigger = true;
    }
    if(key == 'd'){
        hat.setPosition(0);
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(key == 'a'){
        kickTrigger = false;
    }
    if(key == 's'){
        snareTrigger = false;
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
