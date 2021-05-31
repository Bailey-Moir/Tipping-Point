#pragma once
#include "vex.h" 

using namespace vex;

/**
 * The file for the class that holds all of the devices. Motors, sensors, controller, etc.
 * 
 * @author Bailey Moir
 */

namespace Syntech { class Devices {
public:
  static controller remote;
  static brain cortex;
  static competition comp;
  static inertial sensor;
  static motor leftMotor;
  static motor rightMotor;
};};
