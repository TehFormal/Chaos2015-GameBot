#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"
#include "Arm.h"

/*
leftArm
	aForward	6
	aReverse	1
	bForward	7
	bReverse	0

rightArm
	aForward	5
	aReverse	2
	bForward	4
	bReverse	3
*/

DevBot::DevBot():
	robotDrive(frontLeft, rearLeft, frontRight, rearRight),	// Must be initialized in the proper order
	driver(0),
	copilot(1),
	gyro( 0 ),
	compressor(),
	forkliftMotor(5),
	grabber( 1, 0, 7 ), // Channels 0 and 7 on PCM id 1
	rightArm( 2, 5, 3, 4 ),
	leftArm( 1, 6, 0, 7 )
{
	robotDrive.SetExpiration(0.1);
	robotDrive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	robotDrive.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);

	compressor.Start(); // Starts the compressor
}

START_ROBOT_CLASS(DevBot);
