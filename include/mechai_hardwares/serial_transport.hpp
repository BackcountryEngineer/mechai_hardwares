#ifndef SERIAL_TRANSPORT_
#define SERIAL_TRANSPORT_

#include <rclcpp/rclcpp.hpp>

#include "mechai_hardwares/transport_interface.hpp"

namespace mechai_hardwares {
  enum class SerialType {
    CAN,
    UART,
    SPI,
    I2C
  };

  class SerialTransport : public  TransportInterface {
    public:
      virtual SerialType serial_proc() = 0;
  };
} // namespace mechai_hardwares

#endif