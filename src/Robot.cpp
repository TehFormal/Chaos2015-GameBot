#include <cstdint>
#include "WPILib.h"
#include "DevBot.h"

class DevBot: public IterativeRobot
{
private:	
	RobotDrive robotDrive;	// robot drive system
	Joystick stick;		// only joystick
	
public:
	// Constructor Method
	DevBot():

	// Various Iterators
	//void RobotInit();
	//void AutonomousInit();
	//void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
};

DevBot::DevBot():
	robotDrive(frontLeft, rearLeft, frontRight, rearRight),	// Must be initialized in the proper order
	stick(joystickChannel)
{
	robotDrive.SetExpiration(0.1);
	robotDrive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	robotDrive.SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
}

DevBot::TeleopInit() {
	robotDrive.SetSafetyEnabled(false);	// Necessary for proper motor functioning during Teleop
}

DevBot::TeleopPeriodic() {
	robotDrive.MecanumDrive_Cartesian(
		stick.GetX(),			// Lateral movement
		stick.GetY(),			// Forward movement
		stick.GetZ()			// Rotational movement
	);

	Wait(0.005); // Give the CPU some time to breathe so it doesn't explode.
}

START_ROBOT_CLASS(Robot);
