# F1Tenth-Lab2
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

## Problem and Suggested modifications

1. The collision during turning is still possible as the lidar sensing until TTC calculation still need a period of time. (We can slow down the speed during turning, or come out with higher TCC thersold during turning)
