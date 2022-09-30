#ifndef TRANSPORT_INTERFACE_HPP_
#define TRANSPORT_INTERFACE_HPP_

namespace mechai_hardwares {
  class TransportInterface {
    public:
      enum Type {
        ROS,
        SERIAL
      };

      TransportInterface();

      virtual bool init() = 0;
      virtual bool send() = 0;
      virtual bool recieve() = 0;
      virtual bool start_heartbeat() = 0;
      virtual bool shutdown() = 0;
  };
}

#endif