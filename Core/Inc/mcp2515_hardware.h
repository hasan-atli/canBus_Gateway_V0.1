/*
 * mcp2515_hardware.h
 *
 *  Created on: Nov 25, 2022
 *      TORK ROBOTIK
 */

#ifndef INC_MCP2515_HARDWARE_H_
#define INC_MCP2515_HARDWARE_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "stm32f1xx_hal.h"
#include "main.h"


extern SPI_HandleTypeDef hspi1;
extern SPI_HandleTypeDef hspi2;

/***************************************************/
void ChipUnSelectFpB(void);
void ChipSelectFpB(void);
void SPIReadWriteFpB(uint8_t data);
void SPIWriteFpB(uint8_t data);
uint8_t SPIReadFpB(void);


void ChipUnSelectFpC(void);
void ChipSelectFpC(void);
void SPIReadWriteFpC(uint8_t data);
void SPIWriteFpC(uint8_t data);
uint8_t SPIReadFpC(void);


void ChipUnSelectFpD(void);
void ChipSelectFpD(void);
void SPIReadWriteFpD(uint8_t data);
void SPIWriteFpD(uint8_t data);
uint8_t SPIReadFpD(void);
/***************************************************/


#ifdef __cplusplus
}
#endif
#endif /* INC_MCP2515_HARDWARE_H_ */
