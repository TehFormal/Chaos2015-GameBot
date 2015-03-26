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

#ifndef SRC_DEVBOT_H_
#define SRC_DEVBOT_H_

#include <cstdint>
#include "WPILib.h"
#include "LimitedForklift.h"
#include "Arm.h"

// Main Robot Class
class DevBot: public IterativeRobot
{
  private:
	// Actual Motor Controllers
	CANTalon frontRight;
	CANTalon frontLeft;
	CANTalon rearLeft;
	CANTalon rearRight;

	// Fake Motor Controllers
	TalonSRX PWMfr;
	TalonSRX PWMfl;
	TalonSRX PWMrl;
	TalonSRX PWMrr;

	// Controllers
	Joystick driver;
	Joystick copilot;
	
	// Pseudo-Subsystems
	LimitedForklift forklift;
	DoubleSolenoid grabber;
	Arm rightArm;
	Arm leftArm;
	
	// Assorted In's and Out's
	Gyro gyro;
	BuiltInAccelerometer accelerometer;
	Compressor compressor;
	RobotDrive robotDrive;
  public:
	// Constructor Method
	DevBot();

	// Various Iterators
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	
	// Various Helper Functions
	void UpdateMotors();
	void Forward( float Speed, float Time );
	void Backward( float Speed, float Time );
	void Turn( float absSpeed, float targetAngle );
};

#endif /* SRC_DEVBOT_H_ */
