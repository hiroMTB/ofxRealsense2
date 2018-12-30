#pragma once

#include "ofMain.h"
#include <librealsense2/rs.hpp>

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    rs2::pipeline pipe;
    rs2::device device;
    
    rs2::points points;
    rs2::pointcloud pc;
    
    ofVboMesh mesh;
    ofEasyCam cam;
    
};
