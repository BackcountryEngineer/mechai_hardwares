#ifndef SERIAL_TRANSPORT_
#define SERIAL

#include <rclcpp/rclcpp.hpp>

#include "transport_interface.hpp"

namespace mechai_hardwares {
  class SerialTransport : public  TransportInterface {
    public:
      SerialTransport();
      bool send();
      bool recieve();
  };
}

#endif