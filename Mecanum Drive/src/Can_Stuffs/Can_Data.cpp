/*
 * Can_Data.cpp
 *
 *  Created on: Jan 14, 2015
 *      Author: Aeson
 */
#include "Can_Data.h"
#include <iostream>

using namespace std;
Can_Data::Can_Data()
{
	Power = new PowerDistributionPanel;
	voltage = 0;

}

void Can_Data::updateData()
{
	voltage = Power->GetVoltage();

	//cout << voltage << endl;


}



