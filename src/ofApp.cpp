#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //get game data in JSON format
    std::string url = "http://tokensgame-web-ui.herokuapp.com/data/rounds";
    
    // Now parse the JSON
    bool parsingSuccessful = json.open(url);
    
    if (parsingSuccessful)
    {
        ofLogNotice("ofApp::setup") << json.getRawString(true);
    } else {
        ofLogNotice("ofApp::setup") << "Failed to parse JSON.";
    }
    
    ofEnableAlphaBlending();
    ofEnableNormalizedTexCoords();
    for (int i = 0; i < 3; i++) {
        box[i].enableColors();
        box[i].enableTextures();
        box[i].set(50, 300, 50);
    }
    
//    pinstripes.loadImage("Pinstripe_medium.png");
    
    franklinBook.loadFont("frabk.ttf", 24);
    franklinBook.setLineHeight(18.0f);
    franklinBook.setLetterSpacing(1.037);
    
    franklinBookL.loadFont("frabk.ttf", 36);
    franklinBookL.setLineHeight(40.0f);
    franklinBookL.setLetterSpacing(1.037);
}

//--------------------------------------------------------------
void ofApp::update(){
    //convert JSON data to strings
    round = json["rounds"][r]["title"].asString();
    question = "Q:"+json["rounds"][r]["questions"][q].asString();

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0);
    
    //This would be a bar graph for a given token. It would grow or shrink depending on the answer given to the question.
    ofPushStyle();
//    pinstripes.getTextureReference().bind();
    for (int i = 0; i < 3; i++) {
        ofSetColor(0, 255, i*110);
        box[i].setPosition(ofGetWidth()*.2*i+100, ofGetHeight()*.75, 0);
        box[i].draw();
    }
    
//    pinstripes.getTextureReference().unbind();
    ofPopStyle();
    
    ofSetColor(255, 255, 0);
    franklinBook.drawString(round, 3*ofGetWidth()/5, ofGetHeight()/10);
    franklinBookL.drawString(question, 3*ofGetWidth()/5, ofGetHeight()/5);
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    //go to next round
    if (key == 'r') {
        if (r < json["rounds"].size()) {
            r++;
        }
    }
    
    //go to next question
    if (key == 'q') {
        q++;
    }
    
    if (key == 'y') {
        //answer yes to question
    }
    
    if (key == 'n') {
        //answer no to question
    }
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
