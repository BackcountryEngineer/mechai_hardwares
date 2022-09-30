#ifndef MECANUM_WHEEL_SYSTEM__MECANUM_WHEEL_SYSTEM_HPP_
#define MECANUM_WHEEL_SYSTEM__MECANUM_WHEEL_SYSTEM_HPP_

#include <rclcpp_lifecycle/state.hpp>
#include <hardware_interface/system_interface.hpp>

#include "mechai_hardwares/transport_interface.hpp"

namespace mechai_hardwares {
  namespace mecanum_wheel_system {
    constexpr auto LOGNAME = "MecanumWheelSystem";

    class MecanumWheelSystem : public hardware_interface::SystemInterface {
      public:
        MecanumWheelSystem() = default;

        CallbackReturn on_init(const hardware_interface::HardwareInfo & system_info) override;

        CallbackReturn on_configure(const rclcpp_lifecycle::State & previous_state);

        CallbackReturn on_cleanup(const rclcpp_lifecycle::State & previous_state);
        
        CallbackReturn on_shutdown(const rclcpp_lifecycle::State & previous_state);

        CallbackReturn on_activate(const rclcpp_lifecycle::State & previous_state);

        CallbackReturn on_deactivate(const rclcpp_lifecycle::State & previous_state);

        CallbackReturn on_error(const rclcpp_lifecycle::State & previous_state);

        std::vector<hardware_interface::StateInterface> export_state_interfaces();

        std::vector<hardware_interface::CommandInterface> export_command_interfaces();

        hardware_interface::return_type read();

        hardware_interface::return_type write();

      private:
        std::map<std::string, double> velocity_states_;
        std::map<std::string, double> velocity_commands_;
        hardware_interface::HardwareInfo system_info_;
        std::unique_ptr<TransportInterface> hardware_comm_;
    };
  }
}

#endif