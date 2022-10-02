#include <rclcpp/rclcpp.hpp>

#include "mechai_hardwares/uros_pico_transport.hpp"

namespace mechai_hardwares {
  UrosPicoTransport::UrosPicoTransport() {
    //Some ros initialization
  }

  bool UrosPicoTransport::send() {
    return true;
  }

  bool UrosPicoTransport::recieve() {
    return true;
  }

  bool UrosPicoTransport::start_heartbeat() {
    return true;
  }

  bool UrosPicoTransport::shutdown() {
    return true;
  }

  void UrosPicoTransport::on_recieve() {
    
  }
}
