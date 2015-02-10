#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"

DevBot::DevBot():
	robotDrive(frontLeft, rearLeft, frontRight, rearRight),	// Must be initialized in the proper order
	driver(0),
	copilot(1),
	gyro( 0 ),
	compressor(),
	forkliftMotor(5),
	grabber( 1, 0, 7 ) // Channels 0 and 7 on PCM id 1
{
	robotDrive.SetExpiration(0.1);
	robotDrive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	robotDrive.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);

	compressor.Start(); // Starts the compressor
}

START_ROBOT_CLASS(DevBot);
