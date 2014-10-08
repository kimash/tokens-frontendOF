#pragma once

#include "ofMain.h"
#include "ofxJSON.h"

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
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
    ofxJSONElement json;
    
    //sample graph elements since tokens aren't working
    ofBoxPrimitive box[3];
    ofImage pinstripes;
    
    string round;
    string question;
    int r = 0;  //round index
    int q = 0;  //question index

    ofTrueTypeFont  franklinBook;
    ofTrueTypeFont  franklinBookL;
};
