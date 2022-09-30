#ifndef ROS_TRANSPORT_
#define ROS_TRANSPORT_

#include <rclcpp/rclcpp.hpp>

#include "transport_interface.hpp"

namespace mechai_hardwares {
  class RosTransport : public  TransportInterface {
    public:
      RosTransport();
      bool send();
      bool recieve();
      bool start_heartbeat();
      void on_recieve();
  };
}

#endif