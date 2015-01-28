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
	
	// Control Loop for Arm
	//
	// This is in the form of an if-then-elseif loop to prevent the buttons from interfering with
	// one another and to allow for proper resetting.
	//
	// NOTE: For double-acting solenoids, you should always turn off the opposite solenoid before
	//	turning on the one you are trying to activate, so your false's should precede true's in
	//	loops similar to this one.
	if( stick.GetRawButton(0) )		// If the A button is being pressed, move down
	{
		// Set the state of solenoid A
		solenoid0.Set(false);
		solenoid7.Set(false);
		
		// Set the state of solenoid B
		solenoid1.Set(false);
		solenoid6.Set(true);
	
		stopped = false; // Remember that we aren't stopped
	} else if ( stick.GetRawButton(1) )	// Otherwise, if the B button in being pressed, move up
	{
		// Set the state of solenoid A 
		solenoid7.Set(false);
		solenoid0.Set(true);
		
		// Set the state of solenoid B
		solenoid6.Set(false);
		solenoid1.Set(true);
		
		// Reset stopped flag
		stopped = false;
	} else if ( stopped == false )		// If neither is pressed, and we aren't already stopped, stop.
	{
		// Set the state of solenoid A 
		solenoid0.Set(false);
		solenoid7.Set(true);
		
		// Set the state of solenoid B
		solenoid6.Set(false);
		solenoid1.Set(true);
		
		// Set stopped flag
		stopped = true;
	}

	Wait(0.005); // Give the CPU some time to breathe so it doesn't explode.
}
