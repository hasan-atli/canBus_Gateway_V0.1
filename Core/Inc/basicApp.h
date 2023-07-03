/*
 * basicApp.h
 *
 *  Created on: Jun 26, 2023
 *      Author: hasan
 */

#ifndef INC_BASICAPP_H_
#define INC_BASICAPP_H_

#include "torkTypes.h"
#include "stm32f1xx_hal.h"

void Init_CanA();
void Init_Eeprom();
int Get_Eeprom_Adr();
void Init_CanB();
void Init_CanC();
void Init_CanD();
#endif /* INC_BASICAPP_H_ */
