#include "WPILib.h"
#include "Arm.h"

Arm::Arm( int _aLow, int _aHigh, int _bLow, int _bHigh ):
	aLow( _aLow ),
	aHigh( _aHigh ),
	bLow( _bLow ),
	bHigh( _bHigh )
{}

// Sets the solenoids controlling the arm
void Arm::Set( int _state ) {
	if( _state != state ) {
		switch( _state ) {

		// Move Down
		case -1:
			// A Solenoid
			aHigh.Set( false );
			aLow.Set( false );

			// B Solenoid
			bLow.Set( false );
			bHigh.Set( true );

			break;

		// Stop Moving
		case 0:
			// A Solenoid
			aHigh.Set( false );
			aLow.Set( true );

			// B Solenoid
			bHigh.Set( false );
			bLow.Set( true );

			break;

		// Move Up
		case 1:
			// A Solenoid
			aHigh.Set( false );
			aLow.Set( true );

			// B Solenoid
			bLow.Set( false );
			bHigh.Set( true );

			break;

		}
	}
}
