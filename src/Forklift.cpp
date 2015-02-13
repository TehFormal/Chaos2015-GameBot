#include "WPILib.h"
#include "Forklift.h"

Forklift::Forklift( int talon_id ):
	forkliftMotor( talon_id )
{
}

void Forklift::Set( float speed ) {
	forkliftMotor.Set( speed );
}
