cmake_minimum_required(VERSION 3.0.2)
project(safety)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Release)
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
find_package(catkin REQUIRED COMPONENTS
  ackermann_msgs
  geometry_msgs
  nav_msgs
  roscpp
  sensor_msgs
  std_msgs
)

catkin_package()
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(safety_node src/safety_node.cpp)

target_link_libraries(safety_node
  ${catkin_LIBRARIES}
)