#include "ofMain.h"
#include "ofApp.h"
#include "ofAppGLFWWindow.h"

int main( ){
    
    if(1){
        ofGLFWWindowSettings mainSetting;
        mainSetting.setGLVersion(4,1);
        mainSetting.setSize(1280, 720);
        mainSetting.setPosition(ofVec2f(0, 0));
        mainSetting.decorated = true;
        mainSetting.windowMode = OF_WINDOW;
        mainSetting.numSamples = 8;
        
        shared_ptr<ofAppBaseWindow> mainWindow = ofCreateWindow(mainSetting);
        shared_ptr<ofApp> mainApp(new ofApp);
        ofRunApp(mainWindow, mainApp);
        ofRunMainLoop();
    }else{
        ofSetupOpenGL(1280, 720, OF_WINDOW);
        ofRunApp(new ofApp);
    }
    
}
