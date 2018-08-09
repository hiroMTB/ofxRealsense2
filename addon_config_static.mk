meta:
	ADDON_NAME = ofxRealsense2
	ADDON_DESCRIPTION = Addon for Intel librealsense2 (supports D400 series depth camera)
	ADDON_AUTHOR = Hiroshi Matoba
	ADDON_TAGS = "device"
	ADDON_URL = http://github.com/hiroMTB/ofxRealsense2

common:

    ADDON_INCLUDES +=  libs/realsense2/include/
    ADDON_INCLUDES += /usr/local/opt/libusb/include/libusb-1.0

osx:
	ADDON_LIBS  = libs/realsense2/lib/osx/librealsense2.a
	ADDON_LIBS += libs/realsense2/lib/osx/librealsense-file.a
    #ADDON_LIBS += /usr/local/opt/libusb/lib/libusb-1.0.a

	# osx/iOS only, any framework that should be included in the project
	ADDON_FRAMEWORKS += IOKit
	ADDON_FRAMEWORKS += OpenGL
	ADDON_FRAMEWORKS += Cocoa
	ADDON_FRAMEWORKS += CoreVideo

linux64:
linuxarmv6l:
linuxarmv7l:
msys2:
