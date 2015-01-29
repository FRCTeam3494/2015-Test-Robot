#include "WPILib.h"
#include "Can_Stuffs\Can_Data.h"
#include <iostream>


using namespace std;
/**
 * This is a demo program showing how to use Mecanum control with the RobotDrive class.
 */
class Robot: public SampleRobot
{

    // Channels for the wheels
    const static int frontLeftChannel	= 2;
    const static int rearLeftChannel	= 3;
    const static int frontRightChannel	= 1;
    const static int rearRightChannel	= 0;

    const static int joystickChannel	= 0;

    	CANTalon* talons[5];

    	/*CANTalon* Talon_1 ;
    	CANTalon* Talon_2 ;
    	CANTalon* Talon_3 ;
    	CANTalon* Talon_4 ;*/


    //SmartDashboard* Smart;
    Can_Data* Can;
    Encoder encoder_1;
	RobotDrive* robotDrive;	// robot drive system
	Joystick* stick; // only joystick
	bool Period = 0;
	DigitalInput encoder_digital;
	static const int masterID = 1;

	//Talons


public:
	Robot() :  encoder_1(0,1,false, Encoder::k1X),
				// these must be initialized in the same order
	encoder_digital(1)					// as they are declared above.
	{

		for(int i=1;i<5;i++)
		{
			talons[i] = new CANTalon(i);
			talons[i]->SetControlMode(CANSpeedController::kFollower);
			talons[i]->Set(masterID);

		}

		talons[masterID]->EnableControl();
		SmartDashboard::PutString("ENABLED", "TRUE");
		talons[masterID]->SetSafetyEnabled(true);
		talons[masterID]->SetExpiration(0.100);
		talons[masterID]->Set(0);

		// you may need to change or remove this to match your robot
		Can = new Can_Data;
		stick = new Joystick(1);
		//hi
		SmartDashboard::init();
		/*encoder_1.SetSamplesToAverage(5);
		encoder_1.SetDistancePerPulse(1.00 / 360.0 * 2.0 *3.1415 * 1.5);
		encoder_1.SetMinRate(1.0);
		encoder_1.SetReverseDirection(true);
		encoder_1.SetMaxPeriod(1);*/
	}



	/**
	 * Runs the motors with Mecanum drive.
	 */
	void OperatorControl()
	{



		while (IsOperatorControl() && IsEnabled())
		{


			if(!talons[masterID]->IsControlEnabled()){

			}
        	// Use the joystick X axis for lateral movement, Y axis for forward movement, and Z axis for rotation.
        	// This sample does not use field-oriented drive, so the gyro input is set to zero.
			//robotDrive->MecanumDrive_Cartesian(stick.GetX(), stick.GetY(), stick.GetZ());
			//robotDrive->TankDrive(stick->GetRawAxis(4), stick->GetRawAxis(2));
			canData();
			//Talon_1->Set(stick->GetY());
			Wait(0.005); // wait 5ms to avoid hogging CPU cycles

<<<<<<< HEAD
=======
			Period = encoder_1.Get();
>>>>>>> origin/master

			//Period = encoder_digital.Get();

			talons[masterID]->Set(-2);
			Can->updateData();
		}



	}

	//output code stuff
	void canData()
	{

		//Talon Voltage Test

		/*SmartDashboard::PutNumber( "Talon_1 Voltage" , Talon_1->GetBusVoltage() );
		SmartDashboard::PutNumber( "Talon_2 Voltage" , Talon_2->GetBusVoltage() );
		SmartDashboard::PutNumber( "Talon_3 Voltage" , Talon_3->GetBusVoltage() );
		SmartDashboard::PutNumber( "Talon_4 Voltage" , Talon_4->GetBusVoltage() );
		SmartDashboard::PutNumber( "LEFT" , stick->GetRawAxis(4));
		SmartDashboard::PutNumber( "RIGHT" , stick->GetRawAxis(2));*/

		//Talon Voltage Test





	}



};

START_ROBOT_CLASS(Robot);
