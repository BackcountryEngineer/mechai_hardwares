#include <hardware_interface/types/hardware_interface_type_values.hpp>
#include <pluginlib/class_list_macros.hpp>
#include <rclcpp/rclcpp.hpp>

#include "mechai_hardwares/mecanum_wheel_system.hpp"
#include "mechai_hardwares/ros_transport.hpp"
#include "mechai_hardwares/serial_transport.hpp"

namespace mechai_hardwares {
  namespace mecanum_wheel_system {
    CallbackReturn MecanumWheelSystem::on_init(const hardware_interface::HardwareInfo &system_info) {
      system_info_ = system_info;

      RCLCPP_INFO(rclcpp::get_logger(mecanum_wheel_system::LOGNAME), "Initializing transport for hardware comm");
      if (system_info_.hardware_parameters["hardware_transport_type"] == "ros") {
        hardware_comm_ = std::make_unique<RosTransport>();
      } else if (system_info_.hardware_parameters["hardware_transport_type"] == "can") {
        hardware_comm_ = std::make_unique<SerialTransport>();
      }
      RCLCPP_INFO(rclcpp::get_logger(mecanum_wheel_system::LOGNAME), "Initialized mecanum wheel system with %s serial transport for hardware comm.", system_info_.hardware_parameters["hardware_transport_type"]);
    }

    CallbackReturn MecanumWheelSystem::on_configure(const rclcpp_lifecycle::State &previous_state) {
      hardware_comm_->init();
      hardware_comm_->start_heartbeat();
      
    }

    CallbackReturn MecanumWheelSystem::on_cleanup(const rclcpp_lifecycle::State &previous_state) {

    }

    CallbackReturn MecanumWheelSystem::on_shutdown(const rclcpp_lifecycle::State &previous_state) {

    }

    CallbackReturn MecanumWheelSystem::on_activate(const rclcpp_lifecycle::State &previous_state) {

    }

    CallbackReturn MecanumWheelSystem::on_deactivate(const rclcpp_lifecycle::State &previous_state) {

    }

    CallbackReturn MecanumWheelSystem::on_error(const rclcpp_lifecycle::State & previous_state) {

    }

    std::vector<hardware_interface::StateInterface> MecanumWheelSystem::export_state_interfaces() {
      RCLCPP_INFO(rclcpp::get_logger(mecanum_wheel_system::LOGNAME), "export_state_interfaces");
      
      std::vector<hardware_interface::StateInterface> state_interfaces;
      for (auto joint : system_info_.joints) {
        RCLCPP_INFO(rclcpp::get_logger(mecanum_wheel_system::LOGNAME), "Adding %s velocity state interface", joint.name);
        state_interfaces.push_back(
          hardware_interface::StateInterface(
            joint.name,
            hardware_interface::HW_IF_VELOCITY,
            &velocity_states_[joint.name]
          )
        );
      }

      return state_interfaces;
    }

    std::vector<hardware_interface::CommandInterface> MecanumWheelSystem::export_command_interfaces() {
      RCLCPP_INFO(rclcpp::get_logger(mecanum_wheel_system::LOGNAME), "export_state_interfaces");

      std::vector<hardware_interface::CommandInterface> command_interfaces;
      for (auto joint : system_info_.joints) {
        RCLCPP_INFO(rclcpp::get_logger(mecanum_wheel_system::LOGNAME), "Adding %s velocity command interface", joint.name);
        command_interfaces.push_back(
          hardware_interface::CommandInterface(
            joint.name,
            hardware_interface::HW_IF_VELOCITY,
            &velocity_commands_[joint.name]
          )
        );
      }

      return command_interfaces;
    }

    hardware_interface::return_type MecanumWheelSystem::read() {
      hardware_comm_->recieve();
    }

    hardware_interface::return_type MecanumWheelSystem::write() {
      hardware_comm_->send();
    }
  }
}

PLUGINLIB_EXPORT_CLASS(
  mechai_hardwares::mecanum_wheel_system::MecanumWheelSystem,
  hardware_interface::SystemInterface
)