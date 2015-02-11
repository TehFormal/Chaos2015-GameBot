#ifndef SRC_ARM_H_
#define SRC_ARM_H_

/*
+====================================+
| Diagram |                          |
|=========+      **  ==              |
|                ||  ||              |
|    Reverse  | Solnd B  |  Forward  |
|               || || ||             |
|               -- // --             |
|                 //                 |
|                //  ==              |
|                ||  ||              |
|    Reverse  | Solnd A  |  Forward  |
|		        || || ||             |
| == : Cap      == ++ --             |
| ** : Piston                        |
| -- : Air Outlet                    |
| ++ : Compressed Air                |
+====================================+
| Air Flow | Solenoid A | Solenoid B |
|====================================|
| ++ -> ** |  Forward   |  Forward   |
| ** -> -- |    Off     |  Reverse   |
| ** -> == |  Reverse   |  Forward   |
+====================================+
*/

#include "WPILib.h"

class Arm
{
private:
	DoubleSolenoid solenoidA;
	DoubleSolenoid solenoidB;

	// Flag Variables
	int state;

public:
	Arm( int _aForward, int _aReverse, int _bForward, int _bReverse );
	Arm( int _moduleNumber, int _aForward, int _aReverse, int _bForward, int _bReverse );

	// Member Methods
	void Set( int _state );
};

#endif /* SRC_ARM_H_ */
