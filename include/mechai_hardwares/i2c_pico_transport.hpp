#ifndef I2C_PICO_TRANSPORT_
#define I2C_PICO_TRANSPORT_

#include "mechai_hardwares/serial_transport.hpp"

namespace mechai_hardwares
{
  class I2cPicoTransport : public SerialTransport {
    public:
      I2cPicoTransport();
      bool send();
      bool recieve();
      bool start_heartbeat();
      bool shutdown();
      SerialType serial_proc();
  };
} // namespace mechai_hardwares

#endif