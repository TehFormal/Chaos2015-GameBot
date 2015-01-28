#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"

void DevBot::TeleopInit() {
	robotDrive.SetSafetyEnabled(false);	// Necessary for proper motor functioning during Teleop
}

void DevBot::TeleopPeriodic() {
	robotDrive.MecanumDrive_Cartesian(
		-0.5*stick.GetRawAxis(0),		// Lateral movement
		-0.5*stick.GetRawAxis(1),		// Forward movement
		-0.5*stick.GetRawAxis(4)		// Rotational movement
	);

	// Solenoid A
	solenoid0.Set( stick.GetRawButton(1) );
	solenoid7.Set( stick.GetRawButton(2) );

	// Solenoid B
	solenoid1.Set( stick.GetRawButton(3) );
	solenoid6.Set( stick.GetRawButton(4) );

	Wait(0.005); // Give the CPU some time to breathe so it doesn't explode.
}
