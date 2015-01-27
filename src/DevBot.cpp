#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"

DevBot::DevBot():
	robotDrive(frontLeft, rearLeft, frontRight, rearRight),	// Must be initialized in the proper order
	stick(joystickChannel),
	gyro( 0 )
{
	robotDrive.SetExpiration(0.1);
	robotDrive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	robotDrive.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
}

START_ROBOT_CLASS(DevBot);
