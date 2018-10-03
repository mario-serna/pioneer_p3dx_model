#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "mover");
  ros::NodeHandle nh;

  ros::Publisher twist_pub = nh.advertise<geometry_msgs::Twist>("cmd_vel", 1000);

  geometry_msgs::Twist t;
  char cmd[50];
  ros::Rate loop_rate(10);
  t = geometry_msgs::Twist();

  while (ros::ok())
  {
    std::cin.getline(cmd, 50);

    switch (cmd[0]) {
    case 'w':
      t.linear.x += 0.1;
      break;
    case 's':
      t.linear.x -= 0.1;
      break;
    case 'a':
      t.angular.z += 0.1;
      break;
    case 'd':
      t.angular.z -= 0.1;
      break;
    default:
      t = geometry_msgs::Twist();
      break;
    }

    twist_pub.publish(t);

    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
