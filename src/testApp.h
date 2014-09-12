#pragma once

#include "ofMain.h"
#include "ofxGui.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);

        ofxIntSlider pSlider;
        ofxIntSlider qSlider;
        ofxIntSlider rSlider;
        ofxFloatSlider pPhaseSlider;
        ofxFloatSlider qPhaseSlider;
        ofxFloatSlider rPhaseSlider;
        ofxPanel gui;
        int p, q, r;
        bool showGui;
        ofTrueTypeFont font;
};
