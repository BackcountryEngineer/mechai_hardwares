#ifndef MECANUM_WHEEL_SYSTEM__MECANUM_WHEEL_SYSTEM_HPP_
#define MECANUM_WHEEL_SYSTEM__MECANUM_WHEEL_SYSTEM_HPP_

#include <rclcpp/rclcpp.hpp>
#include <rclcpp_lifecycle/state.hpp>

#include <hardware_interface/system_interface.hpp>

namespace mecanum_wheel_system {
  class MecanumWheelSystem : public hardware_interface::SystemInterface {
    public:
      MecanumWheelSystem();

      CallbackReturn on_init(const hardware_interface::HardwareInfo & hardware_info) override;

      CallbackReturn on_configure(const rclcpp_lifecycle::State & previous_state);

      CallbackReturn on_cleanup(const rclcpp_lifecycle::State & previous_state);
      
      CallbackReturn on_shutdown(const rclcpp_lifecycle::State & previous_state);

      CallbackReturn on_activate(const rclcpp_lifecycle::State & previous_state);

      CallbackReturn on_deactivate(const rclcpp_lifecycle::State & previous_state);

      CallbackReturn on_error(const rclcpp_lifecycle::State & previous_state);

    private:
  };
}

#endif