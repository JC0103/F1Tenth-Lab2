# F1Tenth-Lab1
This is a repo for F1Tenth Lab 2 Assignment which implements Automatic Emergency Brake(AEB) using Time to Collision(TTC) Algorithm.

<img src="sample_guide_video.gif"/>

## Dependeices for Running Locally
* ROS Melodic
    * Ubuntu [click here for installation instructions](http://wiki.ros.org/melodic/Installation/Ubuntu)
* F1TENTH Simulator
    * [click here for installation instructions](https://f1tenth.readthedocs.io/en/stable/going_forward/simulator/index.html)

## Basic Build Instructions

1. Clone this repo into catkin_ws/src.
2. Build the ROS package: `catkin build safety`.
3. Launch it: `roslaunch safety AEB_simulation`.