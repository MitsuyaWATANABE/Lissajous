#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    ofBackground(0, 0, 0);
    
    gui.setup(); // most of the time you don't need a name
	gui.add(pSlider.setup("p", 0, 0, 30));
	gui.add(qSlider.setup("q", 1, 0, 30));
	gui.add(rSlider.setup("r", 2, 0, 30));
    
    p = 3;
    q = 1;
    r = 2;
    showGui = true;
	font.loadFont("futura_book.otf", 11);
}

//--------------------------------------------------------------
void testApp::update(){
    
}

//--------------------------------------------------------------
void testApp::draw() {
    ofSetColor(255, 255, 255);
    ofVec3f center = ofVec3f( ofGetWidth() / 2, ofGetHeight() / 2, 0.0);
    
    float s;

    if (showGui) {
        p = pSlider;
        q = qSlider;
        r = rSlider;
        gui.draw();
        
        font.drawString("This is a sample for drawing Lissajous figure.\n\nTyping a key between 0 and 9 display it\nwith generated properties.", 20, 200);
    }
    
    s = 300;
    ofPushMatrix();
    ofTranslate(center);
    ofRotateZ(ofGetElapsedTimef() * 10);
    ofRotateY(ofGetElapsedTimef() * 10);
    ofRotateX(ofGetElapsedTimef() * 10);
    for(float i = 0; i < 2 * PI; i += 0.01) {
        float x = (float)s * sin(p * i);
        float y = (float)s * sin(q * i);
        float z = (float)s * sin(r * i);
        
        ofNoFill();
        ofEllipse(x, y, z, 2, 2);
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
    switch (key) {
        case '0':
            p = 20;
            q = 23;
            r = 29;
            
            break;
        case '1':
            p = 3;
            q = 1;
            r = 2;
            break;
        case '2':
            p = 4;
            q = 1;
            r = 2;
            break;
        case '3':
            p = 5;
            q = 1;
            r = 2;
            break;
        case '4':
            p = 7;
            q = 1;
            r = 2;
            break;
        case '5':
            p = 9;
            q = 4;
            r = 2;
            break;
        case '6':
            p = 11;
            q = 15;
            r = 9;
            break;
        case '7':
            p = 9;
            q = 4;
            r = 5;
            break;
        case '8':
            p = 10;
            q = 12;
            r = 5;
            break;
        case '9':
            p = 11;
            q = 12;
            r = 5;
            break;
            
        case 's':
            showGui = !showGui;
            break;
        default:
            p = 0;
            q = 1;
            r = 2;
            break;
    }
    
    pSlider = p;
    qSlider = q;
    rSlider = r;

}

