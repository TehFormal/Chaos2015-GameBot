#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"

void DevBot::TeleopInit() {
	robotDrive.SetSafetyEnabled(false);	// Necessary for proper motor functioning during Teleop
}

void DevBot::TeleopPeriodic() {
	robotDrive.MecanumDrive_Cartesian(
		-0.5*driver.GetRawAxis(0),		// Lateral movement
		-0.5*driver.GetRawAxis(1),		// Forward movement
		-0.5*driver.GetRawAxis(4)		// Rotational movement
	);

	forkliftMotor.Set( copilot.GetRawAxis(1) );

	if( copilot.GetRawButton(5) ) {
		grabber.Set( DoubleSolenoid::kForward );
	} else if( copilot.GetRawButton(6) ) {
		grabber.Set( DoubleSolenoid::kReverse );
	}

	Wait(0.005); // Give the CPU some time to breathe so it doesn't explode.
}
