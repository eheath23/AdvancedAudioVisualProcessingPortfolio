//
//  branch.cpp
//  AVP_Fractal_Tree
//
//  Created by Eliot Heath on 19/01/2017.
//
//

#include "branch.hpp"

branch::branch(ofVec2f beginPoint, ofVec2f endPoint){
    begin = beginPoint;
    end = endPoint;
}

void show(){
    ofSetColor(255);
//    ofDrawLine((float)begin.x, (float)begin.y, (float)end.x, (float)end.y);
}

void newBranch(){
    
}
