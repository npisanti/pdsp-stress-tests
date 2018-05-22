#pragma once

#include "ofMain.h"
#include "ofxPDSP.h"


class TestSampler : public pdsp::Patchable{
    
public:
    TestSampler() { patch(); } 
    TestSampler( const TestSampler & other ) { patch(); } 
    
    void patch (){
        addModuleInput("trig", triggers );
        addModuleOutput("signal", amp );
        
        env.set(0.0f, 100.0f, 1000.0f); // all the samples used here are shorter than this
        
                          60.f >> p2f;
        triggers >> env * 72.f >> p2f;
                                  p2f >> filter.in_cutoff();
        triggers   >>   sampler     >>   filter;
                                 0.1f >> filter.in_reso();
       
        filter >> amp;
        env >> amp.in_mod();
       
        sampler.addSample( &sample );
    }
    
    void load( string path ){
        sample.load(path);
    }
    
    
private:
    pdsp::PatchNode     triggers;
    pdsp::Sampler       sampler;
    pdsp::AHR           env;
    pdsp::MultiLadder4  filter;
    pdsp::PitchToFreq   p2f;
    
    pdsp::Amp amp;

    pdsp::SampleBuffer sample;
};


class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
        
        ofxPDSPEngine   engine;
        
        std::vector<TestSampler> samplers;
};
