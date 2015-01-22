/*
 * Can_Data.h
 *
 *  Created on: Jan 14, 2015
 *      Author: Aeson
 */

#ifndef SRC_CAN_STUFFS_CAN_DATA_H_
#define SRC_CAN_STUFFS_CAN_DATA_H_

#include "PowerDistributionPanel.h"
#include <iostream>


using namespace std;
class Can_Data
{
public:
	Can_Data();
	void updateData();


private:
	PowerDistributionPanel *Power;
	double voltage;

};


#endif /* SRC_CAN_STUFFS_CAN_DATA_H_ */
