#ifndef ROS_TRANSPORT_
#define ROS_TRANSPORT_

#include "mechai_hardwares/transport_interface.hpp"

namespace mechai_hardwares {
  class RosTransport : public  TransportInterface {
    public:
      virtual void on_recieve() = 0;
  };
} // namespace mechai_hardwares

#endif