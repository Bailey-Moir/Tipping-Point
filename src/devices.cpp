#include "devices.h"

using namespace vex;

namespace Syntech {
  controller Devices::remote = controller();
  brain Devices::cortex = brain();
  competition Devices::comp = competition();
  inertial Devices::sensor = inertial(PORT20);
  motor Devices::leftMotor = motor(PORT9);
  motor Devices::rightMotor = motor(PORT1, true);
};