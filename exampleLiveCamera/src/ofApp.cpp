#include "ofApp.h"

void ofApp::setup(){
    
    ofSetFrameRate(30);
    ofSetVerticalSync(true);
    ofSetLogLevel(OF_LOG_NOTICE);
    ofDisableLighting();
    ofEnableDepthTest();
    ofEnableAlphaBlending();
    ofEnableAntiAliasing();
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    
    pipe.start();
}

void ofApp::update(){

    // Get depth data from camera
    auto frames = pipe.wait_for_frames();
    auto depth = frames.get_depth_frame();
    points = pc.calculate(depth);

    // Create oF mesh
    mesh.clear();
    int n = points.size();
    if(n!=0){
        const rs2::vertex * vs = points.get_vertices();
        for(int i=0; i<n; i++){
            if(vs[i].z){
                const rs2::vertex v = vs[i];
                glm::vec3 v3(v.x,v.y,v.z);
                mesh.addVertex(v3);
                mesh.addColor(ofFloatColor(0,0,ofMap(v.z, 0, 6, 1, 0), 0.8));
            }
        }
    }
}

void ofApp::draw(){
    
    ofBackground(200);
    cam.begin();
    float s = 200;
    ofScale(s,-s,-s);
    ofDrawAxis(1);
    
    ofPushMatrix();
    ofTranslate(0, 1, 0);
    ofRotateZDeg(90);
    ofSetColor(0,200);
    ofDrawGridPlane(1, 5, true);
    ofPopMatrix();
    
    mesh.draw();
    
    cam.end();
}

