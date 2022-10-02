#ifndef UROS_PICO_TRANSPORT_
#define UROS_PICO_TRANSPORT_

#include "mechai_hardwares/ros_transport.hpp"

namespace mechai_hardwares {
  class UrosPicoTransport : public RosTransport {
    public:
      UrosPicoTransport();
      bool send();
      bool recieve();
      bool start_heartbeat();
      bool shutdown();
      void on_recieve();
  };
}

#endif