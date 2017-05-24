#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //Map the mouse position along the Y-axis, from 0 - 100, to the tree length
    startLength = ofMap(mouseY, ofGetHeight(), 0, 0, 100);
    //Map the mouse position along the X-axis, from 0 - 180, to the branch angle
    angle = ofMap(mouseX, ofGetWidth(), 0, 0, 180);
    //Set the multiplier for branch length
    branchMultiplier = 0.7;
    
    //translate to the centre of the screen
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    
    //Draw the first branch
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
