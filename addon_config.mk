meta:
	ADDON_NAME = ofxRealsense2
	ADDON_DESCRIPTION = Addon for Intel librealsense2 (supports D400 series depth camera)
	ADDON_AUTHOR = Hiroshi Matoba
	ADDON_TAGS = "device"
	ADDON_URL = http://github.com/hiroMTB/ofxRealsense2

common:

	ADDON_INCLUDES =  libs/realsense2/include/

osx:
    ADDON_LDFLAGS = -rpath ../../../../addons/ofxRealsense2/libs/realsense2/lib/osx
    ADDON_INCLUDES += /usr/local/opt/libusb/include/libusb-1.0

    #ADDON_LIBS += /usr/local/opt/libusb/lib/libusb-1.0.0.dylib

	# osx/iOS only, any framework that should be included in the project
	ADDON_FRAMEWORKS += IOKit
	ADDON_FRAMEWORKS += OpenGL
	ADDON_FRAMEWORKS += Cocoa
	ADDON_FRAMEWORKS += CoreVideo

vs:	
	# sometimes this does not work, please manually copy files inside of dlls_to_copy folder
	ADDON_DLLS_TO_COPY  = dlls_to_copy

linux64:
linuxarmv6l:
linuxarmv7l:
msys2:
