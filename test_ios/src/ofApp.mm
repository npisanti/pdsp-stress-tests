#include "ofApp.h"

#define VOICES 128

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

    engine.setup( 48000, 1024, 4);
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawBitmapString("running tests", 20, 50 );
}

//--------------------------------------------------------------
void ofApp::touchDown(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchMoved(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchUp(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchDoubleTap(ofTouchEventArgs & touch){

}

//--------------------------------------------------------------
void ofApp::touchCancelled(ofTouchEventArgs & touch){
    
}

//--------------------------------------------------------------
void ofApp::lostFocus(){

}

//--------------------------------------------------------------
void ofApp::gotFocus(){

}

//--------------------------------------------------------------
void ofApp::gotMemoryWarning(){

}

//--------------------------------------------------------------
void ofApp::deviceOrientationChanged(int newOrientation){

}
