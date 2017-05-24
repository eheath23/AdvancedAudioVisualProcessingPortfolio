//
//  branch.hpp
//  AVP_Fractal_Tree
//
//  Created by Eliot Heath on 19/01/2017.
//
//

#ifndef branch_hpp
#define branch_hpp

#include <stdio.h>
#include "ofMain.h"

class branch{
    public:
    branch(ofVec2f, ofVec2f);
    
    void show();
    void newBranch();
    
    ofVec2f begin;
    ofVec2f end;
};

#endif /* branch_hpp */
