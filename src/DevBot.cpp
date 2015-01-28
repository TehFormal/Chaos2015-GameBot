#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"

DevBot::DevBot():
	robotDrive(frontLeft, rearLeft, frontRight, rearRight),	// Must be initialized in the proper order
	stick(joystickChannel),
	gyro( 0 ),
	compressor(),

	// Solenoids
	solenoid0( 0 ),
	solenoid1( 1 ),
	solenoid2( 2 ),
	solenoid3( 3 ),
	solenoid4( 4 ),
	solenoid5( 5 ),
	solenoid6( 6 ),
	solenoid7( 7 )
{
	robotDrive.SetExpiration(0.1);
	robotDrive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	robotDrive.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);

	compressor.Start(); // Starts the compressor
}

START_ROBOT_CLASS(DevBot);
