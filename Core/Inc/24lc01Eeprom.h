/*
 * eeprom.h
 *
 *  Created on: Oct 24, 2022
 *      Author: PC
 */

#ifndef INC_24LC01EEPROM_H_
#define INC_24LC01EEPROM_H_

#include "stdint.h"
#include "stdbool.h"
#include "stm32f1xx_hal.h"

// EEPROM ADDRESS (8bits)
#define EEPROM_ADDR 0xA0

// Define the Page Size and number of pages
#define PAGE_SIZE 8     // in Bytes
#define PAGE_NUM  128    // number of pages

#define EEPROM_I2C &hi2c1
/*****************************************************************************************************************************************/

int  searchI2cDevice(I2C_HandleTypeDef *I2Cx);  //sadece tek slave cihaz varsa adres buluanabilir

void EEPROM_Write (uint8_t devAddr, uint8_t addr, const uint8_t *data, uint16_t data_len);
void EEPROM_Read (uint8_t devAddr, uint8_t addr, uint8_t *data, uint16_t data_len);
void EEPROM_PageErase (uint16_t page);

bool EEPROM_byte_write(uint8_t devAddr, uint8_t addr, const uint8_t data);
uint8_t EEPROM_byte_read(uint8_t devAddr, uint8_t addr);

#endif /* INC_24LC01EEPROM_H_ */
