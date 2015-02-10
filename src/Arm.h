#ifndef SRC_ARM_H_
#define SRC_ARM_H_

#include "WPILib.h"

class Arm
{
private:
	// Solenoid A
	Solenoid aLow;
	Solenoid aHigh;

	// Solenoid B
	Solenoid bLow;
	Solenoid bHigh;

	// Flag Variables
	int state;

public:
	Arm( int _aLow, int _aHigh, int _bLow, int _bHigh );
	Arm( int _moduleNumber, int _aLow, int _aHigh, int _bLow, int _bHigh );

	// Member Methods
	void Set( int _state );
};

#endif /* SRC_ARM_H_ */
