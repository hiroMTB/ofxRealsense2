#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include <librealsense2/rs.hpp>

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
		void keyPressed(int key);

		void pause(bool & b);
		void seek(float & sec);

		ofParameter<bool> pbPause{ "Pause", false};
		ofParameter<float> pbSeek{"Seek (sec)", 0, 0, 100};
		ofParameterGroup playbackGrp{ "Playback", pbPause, pbSeek };
		ofxPanel gui;

		rs2::pipeline pipe;
		rs2::device device;
		rs2::frame depth;
		rs2::frameset frames;
		rs2::points points;
		rs2::pointcloud pc;

		ofVboMesh mesh;
		ofEasyCam cam;

		ofEventListeners cbHolder;
};
