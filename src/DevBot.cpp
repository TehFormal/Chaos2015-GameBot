#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"

DevBot::DevBot():
	robotDrive(frontLeft, rearLeft, frontRight, rearRight),	// Must be initialized in the proper order
	driver(1),
	copilot(2),
	gyro( 0 ),
	compressor(),
	forkliftMotor(5)
{
	robotDrive.SetExpiration(0.1);
	robotDrive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	robotDrive.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);

	compressor.Start(); // Starts the compressor
}

START_ROBOT_CLASS(DevBot);
