#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"
#include "LimitedForklift.h"
#include "Arm.h"

void DevBot::TeleopInit() {
	robotDrive.SetSafetyEnabled(false);	// Necessary for proper motor functioning during Teleop
}

void DevBot::TeleopPeriodic() {
	// Drive
	robotDrive.MecanumDrive_Cartesian(
		-0.5*driver.GetRawAxis(0),		// Lateral movement
		-0.5*driver.GetRawAxis(1),		// Forward movement
		-0.5*driver.GetRawAxis(4)		// Rotational movement
	);

	// Forklift
	forklift.Set( copilot.GetRawAxis(1) );

	// Grabber
	if( copilot.GetRawButton(5) ) {
		grabber.Set( DoubleSolenoid::kForward );
	} else if( copilot.GetRawButton(6) ) {
		grabber.Set( DoubleSolenoid::kReverse );
	}

	// Right Arm
	if( copilot.GetRawButton(1) ) {
		rightArm.Set( -1 );
	} else if( copilot.GetRawButton(2) ) {
		rightArm.Set( 1 );
	} else {
		rightArm.Set( 0 );
	}

	// Left Arm
	if( copilot.GetRawButton(3) ) {
		leftArm.Set( -1 );
	} else if( copilot.GetRawButton(4) ) {
		leftArm.Set( 1 );
	} else {
		leftArm.Set( 0 );
	}

	Wait(0.005); // Give the CPU some time to breathe so it doesn't explode.
}
