#ifndef TRANSPORT_INTERFACE_HPP_
#define TRANSPORT_INTERFACE_HPP_

namespace mechai_hardwares {
  class TransportInterface {
    public:
      virtual bool send() = 0;
      virtual bool recieve() = 0;
      virtual bool start_heartbeat() = 0;
      virtual bool shutdown() = 0;
  };
} // namespace mechai_hardwares

#endif