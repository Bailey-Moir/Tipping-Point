#include "auton.h"

using namespace vex;

using namespace Syntech;

void Syntech::turn(const int degrees, const float efficiency) {
	Devices::sensor.resetRotation();
	P(efficiency, 90, 360, 0.5, degrees, []() { 
		return Devices::sensor.rotation(); 
	}, [](double speed) {
		Devices::leftMotor.spin(fwd, speed, dps);
		Devices::leftMotor.spin(fwd, speed, dps);
	}, []{
		Devices::leftMotor.stop(coast);
		Devices::rightMotor.stop(coast);
	});
	/*					Back-up if we don't have a sesnor
	Devices::leftMotor.resetRotation();
		P(efficiency, 90, 360, 0.5, degrees, []() { 
			return (3.14159 * wheelDiameter * (Devices::leftMotor.rotation(deg) / 360)) / (3.14159 * turnDiameter) * 360;
		}, [](double speed) {
			Devices::leftMotor.spin(directionType::fwd, speed, dps);
			Devices::rightMotor.spin(directionType::rev, speed, dps);
		}, []{
			Devices::leftMotor.stop(coast);
			Devices::rightMotor.stop(coast);
	});
	*/
}

void Syntech::move(float distance, float efficiency) {
	Devices::leftMotor.resetRotation();
	P(efficiency * 10, 10, 720, 0.5, distance, []() { 
		// C		= πd
		// Length	= πd * degrees / 360
		return 3.14159 * wheelDiameter * (Devices::leftMotor.rotation(deg) / 360);
	}, [](double speed) {
		Devices::leftMotor.spin(directionType::fwd, speed, dps);
		Devices::rightMotor.spin(directionType::fwd, speed, dps);
	}, []{
		Devices::leftMotor.stop(coast);
		Devices::rightMotor.stop(coast);
  });
}

void Syntech::moveTime(int time, int _dps) {
	Devices::leftMotor.spin(fwd, _dps, dps);
	Devices::rightMotor.spin(fwd, _dps, dps);

	wait(time, msec);
	
	Devices::leftMotor.stop(coast);    
	Devices::rightMotor.stop(coast);
}

void Syntech::moveTimeDistance(float roughDistance, int _dps) {
	Devices::leftMotor.spin(fwd, _dps, dps);
	Devices::rightMotor.spin(fwd, _dps, dps);

	// distance		= πd * degrees / 360
	// degrees		= (360 * distance) / πd 
	// degrees/_dps	= s
	// s			= (360 * distance) / πd * _dps
	wait((360 * roughDistance) / (3.14159 * wheelDiameter * _dps) + 0.3, sec);

	Devices::leftMotor.stop(coast);    
	Devices::rightMotor.stop(coast);

}

void Syntech::P(const float efficiency, const int min, const int max, const float margin, const float desired, double(*independent)(), void(*loop)(double error), void(*stop)()) {
	while (!(desired - independent() < margin / 2 && desired - independent() > -margin / 2)) {
    // Gets the previous error
    double error = (desired - independent()) * efficiency;

    // Caps the error.
    if (error > max) error = max;
    if (error < -max) error = -max;
    if (error < min && error > 0) error = min;
    if (error > -min && error < 0) error = -min;

    loop(error);

    wait(20, msec);
	}
  stop();  
}