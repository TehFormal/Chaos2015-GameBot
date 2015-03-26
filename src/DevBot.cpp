#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"
#include "LimitedForklift.h"
#include "Arm.h"

DevBot::DevBot():
	// Actual Motor Controllers
	frontRight( 1 ),
	frontLeft( 2 ),
	rearLeft( 3 ),
	rearRight( 4 ),

	// Fake Motor Controllers
	PWMfr( 0 ),
	PWMfl( 1 ),
	PWMrl( 2 ),
	PWMrr( 3 ),
	
	// Controllers
	driver( 0 ),
	copilot( 1 ),
	
	// Pseudo-Subsystems
	forklift( 5, 6, 0, 1 ),
	grabber( 1, 0, 7 ),
	rightArm( 2, 5, 3, 4 ),
	leftArm( 1, 6, 0, 7 ),
	
	// Assorted In's and Out's
	gyro( 0 ),
	accelerometer(),
	compressor(),
	robotDrive( PWMfl, PWMrl, PWMfr, PWMrr )
{
	// Mecanum Boilerplate
	robotDrive.SetInvertedMotor( RobotDrive::kFrontLeftMotor, true );
	robotDrive.SetInvertedMotor( RobotDrive::kRearLeftMotor, true );
	
	// Other Assorted Setup
	robotDrive.SetExpiration( 0.3 );
	compressor.Start();
}

void DevBot::UpdateMotors() {
	// Set real motor values based off of the fake ones
	frontRight.Set(PWMfr.Get());
	frontLeft.Set(PWMfl.Get());
	rearLeft.Set(PWMrl.Get());
	rearRight.Set(PWMrr.Get());
}

START_ROBOT_CLASS(DevBot);
