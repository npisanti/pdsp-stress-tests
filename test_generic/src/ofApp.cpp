#include "ofApp.h"

#define VOICES 256

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
    
    engine.listDevices();
    engine.setDeviceID(0); 
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
void ofApp::keyPressed(int key){
    switch ( key ){
        case ' ':
            if(engine.score.isPlaying()){
                engine.score.pause();
            }else{
                engine.score.play();
            }
        break;
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

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
