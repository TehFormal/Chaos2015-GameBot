/*******************************************************************************
* Arm.h - This class allows for two double-acting solenoids (arranged like     *
*         the diagram below) to be used in a way which resembles the           *
*         pneumatic equivilant of a half H-Bridge.                             *
********************************************************************************

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
|               || || ||             |
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

#ifndef SRC_ARM_H_
#define SRC_ARM_H_

#include "WPILib.h"

class Arm {
  public:
	Arm( int _aForward, int _aReverse, int _bForward, int _bReverse );
	Arm( int _moduleNumber, int _aForward, int _aReverse, int _bForward, int _bReverse );

	void Set( int state );

  private:
	DoubleSolenoid solenoidA;
	DoubleSolenoid solenoidB;
};

#endif /* SRC_ARM_H_ */
