# Intelligent-Mobile-Robot-IMR
We've built an autonomous mobile robot entitled IMR ( Intelligent Mobile Robot ). <br>
We will show How to build an Autonomous car with ROS. <br>
We made this repository of our mobile robot to help people install and configure their robots from the original Linorobot repository without encountering any problems.
## Tutorial
You can read the full tutorial on how to build your Autonomous car on [our website](https://mostafasaleh1.github.io/graduation-project-website/).
### Requirements
#### Hardware
- Kinect v2
- Arduino Mega
- Motors driver (l298)
- DC motor with Encoder (4wd)
- esp 32 
- laptop (for processing)
- servo motors (for your arm)
- Step Down module 5v 3A
- MPU IMU 6050
- Batteries
####  Software 
- Ubuntu 18.4 [here](http://releases.ubuntu.com/18.04/ubuntu-18.04.6-desktop-amd64.iso).
- ROS Melodic
#### Structure
- Any shape compatible with your case 
### Installation 
we used the Linorobot packages [here](https://linorobot.org/) and we thank the Linorobot team to build this package <br>
these steps like prerequisites 
make sure you clone the repo from a melodic branch or any alternative branch mentioned in [ROS WIKI](http://wiki.ros.org/Documentation) 
- Install your Ubuntu [follow these steps](https://ubuntu.com/tutorials/install-ubuntu-desktop#1-overview)
- Install ROS Melodic [follow these steps](http://wiki.ros.org/melodic/Installation/Ubuntu)
- Install Arduino use Arduino in my Repo
- Create workSpace [follow these steps](http://wiki.ros.org/catkin/Tutorials/create_a_workspace)
- Install Kinect driver
- finally use my workspace 
##### Install Arduino 
copied files in from my Repo to the home directory or install Arduino from the official website and [follow these steps](http://wiki.ros.org/rosserial_arduino/Tutorials/Arduino%20IDE%20Setup) to install libraries make sure you install the Rosserial library correctly you can compare it with the one in my files 
##### Install Kinect v2
got to [libfreenect2](https://github.com/OpenKinect/libfreenect2.git) and cloned the repo in home
```
git clone https://github.com/OpenKinect/libfreenect2.git
cd libfreenect2
sudo apt-get install build-essential cmake pkg-config
sudo apt-get install libusb-1.0-0-dev
sudo apt-get install libturbojpeg0-dev
sudo apt-get update
sudo apt-get install libglfw3-dev
sudo apt-get install beignet-dev # (find the appropriate one)
```
Then install the python freenect2 lib <br>
add the following line ``` export PKG_CONFIG_PATH=$PKG_CONFIG_PATH:$HOME/freenect2/lib/pkgconfig``` and ```export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$HOME/freenect2/lib``` to ```~/.bashrc``` <br>
<br>
in libfreenect2 directory
```
mkdir build && cd build
cmake .. -DCMAKE_INSTALL_PREFIX=$HOME/freenect2 -Dfreenect2_DIR=$HOME/freenect2/lib/cmake/freenect2
make
make install

sudo cp ../platform/linux/udev/90-kinect2.rules /etc/udev/rules.d/
./bin/Protonect # to test your kinect
```
then install <strong> iai-Kinect2</strong><br>
Follow these steps I recommended to use the official Repo [here](https://github.com/code-iai/iai_kinect2/tree/master) <br>
#### Use my WorkSpace
copy directories in <strong>v2-our work space</strong> to your workspace <br>
Follow this steps
```
cp "v2-our work space/*" ~/catkin_ws/src
unzip linorobot.zip
rm linorobot.zip
unzip rosserial.zip
rm rosserial.zip
unzip rtabmap_ros.zip
rm rtabmap_ros.zip
cd ~/catkin_ws
catkin_make
```
if you found any errors with catkin make, make sure you have installed the compatible package with
```
sudo apt install ros-melodic-yourpackage
```
#### Finally follow these Tutorial [Linorobot](https://github.com/linorobot/linorobot/wiki) to understand more about How to build your autonmous car 
