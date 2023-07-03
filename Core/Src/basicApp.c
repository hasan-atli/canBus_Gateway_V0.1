/*
 * basicApp.c
 *
 *  Created on: Jun 26, 2023
 *      Author: hasan
 */

#include "basicApp.h"
#include "debug.h"
#include "main.h"
#include "24lc01Eeprom.h"
#include "mcp2515_drv.h"
#include "mcp2515_hardware.h"
#include "canMsg.h"
#include "canMsgRingBuf.h"

extern CAN_TxHeaderTypeDef txHeader;   //CAN Bus Receive Header
extern CAN_FilterTypeDef canfil;       //CAN Bus Filter
extern uint32_t period_of_led_blink;

extern CAN_HandleTypeDef hcan;
extern I2C_HandleTypeDef hi2c1;

/*****************************************************************************/
// for EEPROM
int EEPROM_DEVICE_ADR = 0;
// for canB nad CanC comm
CanbusConfig_t cfgCanB;   //spi1
CanbusConfig_t cfgCanC;   //spi2
CanbusConfig_t cfgCanD;   //spi2
/*****************************************************************************/

/**********************************************************/
/*  Name        : Init_CanA
//  Parameters  : void
//  Returns     :
//  Scope       :
//  Function    :
/*--------------------------------------------------------*/
void Init_CanA() {
	canfil.FilterBank = 0;
	canfil.FilterMode = CAN_FILTERMODE_IDMASK;
	canfil.FilterFIFOAssignment = CAN_RX_FIFO0;
	canfil.FilterIdHigh = 0;
	canfil.FilterIdLow = 0;
	canfil.FilterMaskIdHigh = 0;
	canfil.FilterMaskIdLow = 0;
	canfil.FilterScale = CAN_FILTERSCALE_32BIT;
	canfil.FilterActivation = ENABLE;
	canfil.SlaveStartFilterBank = 14;

	txHeader.DLC = 8;
	txHeader.IDE = CAN_ID_STD;
	txHeader.RTR = CAN_RTR_DATA;
	txHeader.StdId = 0x7FF;
	txHeader.ExtId = 0x1FFFFFFF;
	txHeader.TransmitGlobalTime = DISABLE;

	if(HAL_OK != HAL_CAN_ConfigFilter(&hcan, &canfil))
	{
		debugPrintf("CAN_A_FAIL\n");
		period_of_led_blink = _100_MS;
		return;
	}

	if(HAL_OK != HAL_CAN_Start(&hcan))
	{
		debugPrintf("CAN_A_FAIL\n");
		period_of_led_blink = _100_MS;
		return;
	}

	if(HAL_OK != HAL_CAN_ActivateNotification(&hcan, CAN_IT_RX_FIFO0_MSG_PENDING))
	{
		debugPrintf("CAN_A_FAIL\n");
		period_of_led_blink = _100_MS;
		return;
	}
	debugPrintf("CAN_A_OK\n");
}


/**********************************************************/
//  Name        : Init_Eeprom
//  Parameters  : void
//  Returns     :
//  Scope       :
//  Function    :
/*--------------------------------------------------------*/
void Init_Eeprom()
{
	EEPROM_DEVICE_ADR = searchI2cDevice(&hi2c1);

	if(EEPROM_DEVICE_ADR != HAL_ERROR)
	{
		debugPrintf("EEPROM_OK,  adr: %x\n", EEPROM_DEVICE_ADR);
	}
	else
	{
		period_of_led_blink = _100_MS;
		debugPrint("eeprom init FAIL\n ");
	}
}


/**********************************************************/
//  Name        : Get_Eeprom_Adr
//  Parameters  : int
//  Returns     :
//  Scope       :
//  Function    :
/*--------------------------------------------------------*/
int Get_Eeprom_Adr()
{
	return EEPROM_DEVICE_ADR;
}


/**********************************************************/
//  Name        : Init_CanB
//  Parameters  : void
//  Returns     :
//  Scope       :
//  Function    :
/*--------------------------------------------------------*/
void Init_CanB()
 {
	/****CanB***/
	// declaring  hardware related pointer func.
	cfgCanB.ChipSelectFp = &ChipSelectFpB;
	cfgCanB.ChipUnSelectFp = &ChipUnSelectFpB;
	cfgCanB.SPIReadFp = &SPIReadFpB;
	cfgCanB.SPIReadWriteFp = &SPIReadWriteFpB;
	cfgCanB.SPIWriteFp = &SPIWriteFpB;

	// init
	ChipUnSelectFpB();

	uint8_t result = begin(&cfgCanB, CAN_500KBPS, MCP_8MHz);
	// can the CAN run
	if (result == CAN_OK) {
		debugPrint("CAN_B_OK\n");
	}
	else {
		period_of_led_blink = _100_MS;
		debugPrint("CAN_B_FAIL\n");
	}

}


/**********************************************************/
//  Name        : Init_CanC
//  Parameters  : void
//  Returns     :
//  Scope       :
//  Function    :
/*--------------------------------------------------------*/
void Init_CanC() {
	/****CanC***/
	// declaring  hardware related pointer func.
	cfgCanC.ChipSelectFp = &ChipSelectFpC;
	cfgCanC.ChipUnSelectFp = &ChipUnSelectFpC;
	cfgCanC.SPIReadFp = &SPIReadFpC;
	cfgCanC.SPIReadWriteFp = &SPIReadWriteFpC;
	cfgCanC.SPIWriteFp = &SPIWriteFpC;

	// init
	ChipUnSelectFpC();

	uint8_t result = begin(&cfgCanC, CAN_500KBPS, MCP_8MHz);
	//can the CAN run
	if (result == CAN_OK) {
		debugPrint("CAN_C_OK\n");
	}
	else {
		period_of_led_blink = _100_MS;
		debugPrint("CAN_C_FAIL\n");
	}
}


/**********************************************************/
//  Name        : Init_CanD
//  Parameters  : void
//  Returns     :
//  Scope       :
//  Function    :
/*--------------------------------------------------------*/
void Init_CanD()
{
	/****CanC***/
	// declaring  hardware related pointer func.
	cfgCanD.ChipSelectFp = &ChipSelectFpD;
	cfgCanD.ChipUnSelectFp = &ChipUnSelectFpD;
	cfgCanD.SPIReadFp = &SPIReadFpD;
	cfgCanD.SPIReadWriteFp = &SPIReadWriteFpD;
	cfgCanD.SPIWriteFp = &SPIWriteFpD;

	// init
	ChipUnSelectFpD();

	uint8_t result = begin(&cfgCanD, CAN_500KBPS, MCP_8MHz);
	//can the CAN run
	if (result == CAN_OK) {
		debugPrint("CAN_D_OK\n");
	}
	else {
		period_of_led_blink = _100_MS;
		debugPrint("CAN_D_FAIL\n");
	}

}
