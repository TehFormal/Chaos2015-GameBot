#include "WPILib.h"

class Robot: public IterativeRobot
{
public:
	// Constructor Method
	Robot();

	// Various Iterators
	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};

START_ROBOT_CLASS(Robot);
