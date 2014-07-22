#ifndef BLUEFOX2_ROS_CAMERA_H_
#define BLUEFOX2_ROS_CAMERA_H_

#include <memory>

#include <ros/ros.h>
#include <image_transport/image_transport.h>
#include <sensor_msgs/Image.h>
#include <sensor_msgs/CameraInfo.h>
#include <camera_info_manager/camera_info_manager.h>

#include "opencv2/core/core.hpp"

#include "bluefox2/camera.h"

namespace bluefox2 {

class RosCamera {
 public:
  RosCamera(const ros::NodeHandle &nh);
  void PublishImage(const cv::Mat &image);

  std::unique_ptr<Camera> camera;
 private:
  ros::NodeHandle nh_;
  std::string frame_id_;
  image_transport::ImageTransport it_;
  image_transport::CameraPublisher camera_pub_;
  sensor_msgs::ImagePtr image_;
  sensor_msgs::CameraInfoPtr cinfo_;

};  // class SingleCamera

}  // namespace bluefox2

#endif  // BLUEFOX2_SINGLE_SINGLE_CAMERA_H_
