# ofxRealsense2
This repos is openFrameworks addon fo [Intel® RealSense™ SDK 2.0](https://github.com/IntelRealSense/librealsense). You can test your D400 series camera quickly. If you dont have device, you cann still playback BAG files and see how it works (for example performance, postprocessing, depth quality, etc)

## Development period
- 2018.7 ~ active

## Version
- Realsense 2.14.1 (released on 2018.7)
- libusb 1.0.22
- openFrameworks 0.10.0

## TODO
- [x] OSX support
- [x] Windows support
- [ ] Linux support
- [x] add ci scripts
- [ ] add postprocessing example
- [ ] add bag file playback example

## Install Realsense SDK
Follow the official instalaction [here](https://realsense.intel.com/sdk-2/) and check you can launch realsense viewer.

## Using oF Poroject Generator

This repo does not contain any project file. Please generate project file by yourself.
Project Generator needs addon_config.make for setting library properly. This repo contain follwing two .make. Please rename your favorite one to addon_config.make.

- addon_config_shared.make : Generate project file which use shared library(.dylib, .dll + .lib)
- addon_config_static.make : Generate project file which use static library(.a, .lib). 

## Static library vs Shared library

### osx + static lib (.a)
Realsense static lib for OSX is only avairable by compiling source code by yourself.
But generated .a file is large over 180MB. So I dont put it in this repo. Please compile it by yourself(git LFS later maybe).

### osx + shared lib (.dylib)
Shared lib is small enough (9.8MB) and you can find in this repo under /libs directory. Release version only. However because of osx app package system, you can not excute .app by double click when you use shared lib. You may need additional process to make standalone app. More details in this [thread in oF forum](https://forum.openframeworks.cc/t/dynamic-libraries-for-osx-addon/19908/11
).

## Compile your own Realsense library
Compiling realsense library is straight forward.
1. download zip source from [Intel® RealSense™ SDK 2.0 github repo](https://github.com/IntelRealSense/librealsense)
2. cmake (app or ccmake)
3. set option (like BUILD_SHARED_LIBS) and generate project files
4. build with Xcode or Visual Studio etc
* please double check cmake's BUILD_WITH_OPENMP option is off since better performance without OpenMP. Please ask to google for details.

## BAG file (rosbag)
With Realsense Viewer you can record/playback depth & color stream to bag file. SDK also support rec & playback. But recorded bag file is super big like 1GB for 10 sec. Please record your own bag file and put it in /examplePlayback/bin/data folder. (btw why it's so big? OpenNI's .oni file is way too small like 30MB for 10 sec).

## Hardware
- Sometimes I experienced collapesed data stream when I use USB 3.0 extension cable from D435 camera.
Unplug and plug camera again if you see strange data.
- The quality of depth data from D400 series is depends on parameter of postprocessing. I recommend to check out [this PDF article](https://realsense.intel.com/wp-content/uploads/sites/63/BKM-For-Tuning-D435-and-D415-Cameras-Webinar_Rev3.pdf) and test with Realsense Viewer. 

## Notice
### libusb in osx
- libusb is NOT included in this repo. Should be installed to your system with 'brew install libusb' at first SDK install step.