#include "WPILib.h"
#include "Arm.h"

Arm::Arm( int _aForward, int _aReverse, int _bForward, int _bReverse ):
	solenoidA( _aForward, _aReverse ),
	solenoidB( _bForward, _bReverse )
{
}

Arm::Arm( int _moduleNumber, int _aForward, int _aReverse, int _bForward, int _bReverse ):
	solenoidA( _moduleNumber, _aForward, _aReverse ),
	solenoidB( _moduleNumber, _bForward, _bReverse )
{
}

// Sets the solenoids controlling the arm
void Arm::Set( int state ) {
	switch( state ) {

	// Move Down
	case -1:
		solenoidA.Set( DoubleSolenoid::kOff );
		solenoidB.Set( DoubleSolenoid::kReverse );
		break;

	// Stop Moving
	case 0:
		solenoidA.Set( DoubleSolenoid::kReverse );
		solenoidB.Set( DoubleSolenoid::kForward );
		break;

	// Move Up
	case 1:
		solenoidA.Set( DoubleSolenoid::kForward );
		solenoidB.Set( DoubleSolenoid::kForward );
		break;

	}
}
