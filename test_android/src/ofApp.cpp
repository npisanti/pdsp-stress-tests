#include "ofApp.h"

#define VOICES 16

//--------------------------------------------------------------
void ofApp::setup(){

    ofBackground(0);

    samplers.resize( VOICES );
    engine.score.init( VOICES, 1, 150.0f);

    for( int i=0; i<VOICES; ++i){

        samplers[i].load( ofToDataPath("rain.ogg") );

        engine.score.sections[i].sequence(0).set( { 1.f, -1.f }, 1.0, 2.0 );
        engine.score.sections[i].launchCell(0);

        engine.score.sections[i].out_trig(0) >> samplers[i];

        samplers[i] * (0.7f/(float)VOICES) >> engine.audio_out(0);
        samplers[i] * (0.7f/(float)VOICES) >> engine.audio_out(1);

    }

    engine.setup( 44100, 512, 3);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString("running tests", 20, 50 );
}

//--------------------------------------------------------------
void ofApp::exit(){
    
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::touchDown(int x, int y, int id){
}

//--------------------------------------------------------------
void ofApp::touchMoved(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchUp(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::touchCancelled(int x, int y, int id){

}

//--------------------------------------------------------------
void ofApp::swipe(ofxAndroidSwipeDir swipeDir, int id){

}

//--------------------------------------------------------------
void ofApp::pause(){

}

//--------------------------------------------------------------
void ofApp::stop(){

}

//--------------------------------------------------------------
void ofApp::resume(){

}

//--------------------------------------------------------------
void ofApp::reloadTextures(){

}

//--------------------------------------------------------------
bool ofApp::backPressed(){
    return false;
}

//--------------------------------------------------------------
void ofApp::okPressed(){

}

//--------------------------------------------------------------
void ofApp::cancelPressed(){

}

