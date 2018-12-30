#include "ofApp.h"

void ofApp::setup() {

	ofSetFrameRate(30);
	ofSetVerticalSync(true);
	ofSetLogLevel(OF_LOG_NOTICE);

	//	test.bag file is not included in this repo.
	//	Please record by yourself with Realsense Viewer.
	string bagFilePath = ofToDataPath("test.bag", true);
	ofFile bagFile(bagFilePath);
	if (!bagFile.exists()) {
		ofLogError() << "Couldn't find BAG file : " << bagFilePath;
		ofLogError() << "EXIT";
		ofExit();
	}else {
		ofLogNotice() << "Font BAG file : " << bagFilePath;
	}

	rs2::config cfg;
	cfg.enable_device_from_file(bagFilePath);
	pipe.start(cfg);

	device = pipe.get_active_profile().get_device();

	if (device.as<rs2::playback>()) {
		rs2::playback playback = device.as<rs2::playback>();
		std::chrono::nanoseconds total_duration = playback.get_duration();
		std::chrono::seconds sec = std::chrono::duration_cast<std::chrono::seconds>(total_duration);
		pbSeek.setMax(sec.count());
	}
	cout << "device info : " << device.get_info(rs2_camera_info::RS2_CAMERA_INFO_NAME) << endl;

	// gui
	gui.setup("settings", "settings.xml");
	gui.add(playbackGrp);
	gui.loadFromFile("settings.xml");

	pbPause.addListener(this, &ofApp::pause);
	pbSeek.addListener(this, &ofApp::seek);
}

void ofApp::pause(bool & b) {
	if (device.as<rs2::playback>()) {
		rs2::playback playback = device.as<rs2::playback>();
		b ? playback.pause() : playback.resume();
	}
}

void ofApp::seek(float & sec) {
	if (device.as<rs2::playback>()) {
		rs2::playback playback = device.as<rs2::playback>();
		std::chrono::duration<float> s(sec);
		playback.seek(std::chrono::duration_cast<std::chrono::nanoseconds>(s));
	}
}

void ofApp::update(){

	// playback
	if (device.as<rs2::playback>()) {
		rs2::playback playback = device.as<rs2::playback>();

		if (pipe.poll_for_frames(&frames)) {
			depth = frames.get_depth_frame();
			points = pc.calculate(depth);

			chrono::nanoseconds pos(playback.get_position());
			float sec = pos.count() * 0.001 * 0.001 * 0.001;
			pbSeek = sec;
		}
	}

	// Create oF mesh
	mesh.clear();
	int n = points.size();
	if (n != 0) {
		const rs2::vertex * vs = points.get_vertices();
		const rs2::texture_coordinate * ts = points.get_texture_coordinates();

		for (int i = 0; i < n; i++) {
			if (vs[i].z) {
				const rs2::vertex v = vs[i];
				glm::vec3 v3(v.x, v.y, v.z);
				mesh.addVertex(v3);
				mesh.addColor(ofFloatColor(0, 0, ofMap(v.z, 2, 6, 1.0, 0), 0.8));
			}
		}
	}
}

void ofApp::draw(){

	ofEnableDepthTest();
	ofBackground(200);
	cam.begin();
	float s = 200;
	ofScale(s, -s, -s);
	ofDrawAxis(1);

	ofPushMatrix();
	ofTranslate(0, 1, 0);
	ofRotateZDeg(90);
	ofSetColor(0, 200);
	ofDrawGridPlane(1, 5, true);
	ofPopMatrix();

	mesh.drawVertices();

	cam.end();

	ofDisableDepthTest();
	gui.draw();
}

void ofApp::keyPressed(int key){

	switch (key) {

	case ' ':
		pbPause = !pbPause;
		break;

	case '0':
		pbSeek = 0;
		break;
	}

}
