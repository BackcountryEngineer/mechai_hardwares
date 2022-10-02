#include "mechai_hardwares/i2c_pico_transport.hpp"

namespace mechai_hardwares
{
  I2cPicoTransport::I2cPicoTransport() {
    //Initialize some serial communication stuff
  }

  bool I2cPicoTransport::send() {
    return true;
  }

  bool I2cPicoTransport::recieve() {
    return true;
  }

  bool I2cPicoTransport::start_heartbeat() {
    return true;
  }

  bool I2cPicoTransport::shutdown() {
    return true;
  }

  SerialType I2cPicoTransport::serial_proc() {
    return SerialType::I2C;
  }
} // namespace mechai_hardwares