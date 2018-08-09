#pragma once

#include "ofMain.h"
#include <librealsense2/rs.hpp>

class ofApp : public ofBaseApp{
public:
    void setup();
    void update();
    void draw();
    
    void loadBagFile(string path);
    
    rs2::pipeline pipe;
    rs2::device device;
    rs2::colorizer color_map;
    rs2::frame colored_depth;
    rs2::frame colored_filtered;
    
    rs2::points points;
    rs2::pointcloud pc;
    
    ofVboMesh mesh;
    ofEasyCam cam;
    
};
