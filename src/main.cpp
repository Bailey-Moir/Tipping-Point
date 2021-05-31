#include "vex.h"
#include <cstdlib>
#include "devices.h"
#include "auton.h"

using namespace Syntech;
using namespace vex;

/**
 * The starting off point of the program.
 * 
 * @author Bailey Moir
 */

/**
 * Initalises the devices (that need to be initalised).
 */
void vexcodeInit() {
  Devices::sensor.calibrate();
}

/**
 * The code that runs for the autunomous.
 */
void auton() {
  waitUntil(!Devices::sensor.isCalibrating());
  
  /*---------------------
    Insert instructions
  ---------------------*/
}

/**
 * The code that runs at the start of user control.
 */
void control() {
  while (true) {
    Devices::remote.ButtonA.pressed(auton);

    Devices::leftMotor.spin(fwd, 360 * Devices::remote.Axis3.value(), dps);
    Devices::rightMotor.spin(fwd, 360 * Devices::remote.Axis2.value(), dps);
  }
}  

/**
 * The origin of the main thread.
 */
int main() {
  vexcodeInit();

  Devices::comp.autonomous(auton);
  Devices::comp.drivercontrol(control);
}