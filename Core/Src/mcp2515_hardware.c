/*
 * mcp2515_hardware.c
 *
 *  Created on: Nov 25, 2022
 *      TORK ROBOTIK
 */

#include "mcp2515_hardware.h"



void ChipUnSelectFpB(void)
{
	HAL_GPIO_WritePin(CS_CAN_B_GPIO_Port, CS_CAN_B_Pin, GPIO_PIN_SET);
}

void ChipSelectFpB(void)
{
	HAL_GPIO_WritePin(CS_CAN_B_GPIO_Port, CS_CAN_B_Pin, GPIO_PIN_RESET);
}

void SPIReadWriteFpB(uint8_t data)
{
	HAL_SPI_Transmit(&hspi1, (uint8_t *)&data, 1, 100);
}

void SPIWriteFpB(uint8_t data)
{
	 HAL_SPI_Transmit(&hspi1, (uint8_t *)&data, 1, 100);
}

uint8_t SPIReadFpB(void)
{
	uint8_t data = 0x00;

	HAL_SPI_Receive(&hspi1, (uint8_t *)&data, 1, 100);

	return data;
}

void ChipUnSelectFpC(void)
{
	HAL_GPIO_WritePin(CS_CAN_C_GPIO_Port, CS_CAN_C_Pin, GPIO_PIN_SET);
}

void ChipSelectFpC(void)
{
	HAL_GPIO_WritePin(CS_CAN_C_GPIO_Port, CS_CAN_C_Pin, GPIO_PIN_RESET);
}

void SPIReadWriteFpC(uint8_t data)
{
	 HAL_SPI_Transmit(&hspi2, (uint8_t *)&data, 1, 100);
}

void SPIWriteFpC(uint8_t data)
{
	 HAL_SPI_Transmit(&hspi2, (uint8_t *)&data, 1, 100);
}

uint8_t SPIReadFpC(void)
{
	uint8_t data = 0x00;

	HAL_SPI_Receive(&hspi2, (uint8_t *)&data, 1, 100);

	return data;
}


void ChipUnSelectFpD(void)
{
	HAL_GPIO_WritePin(CS_CAN_D_GPIO_Port, CS_CAN_D_Pin, GPIO_PIN_SET);
}

void ChipSelectFpD(void)
{
	HAL_GPIO_WritePin(CS_CAN_D_GPIO_Port, CS_CAN_D_Pin, GPIO_PIN_RESET);
}

void SPIReadWriteFpD(uint8_t data)
{
	 HAL_SPI_Transmit(&hspi2, (uint8_t *)&data, 1, 100);
}

void SPIWriteFpD(uint8_t data)
{
	 HAL_SPI_Transmit(&hspi2, (uint8_t *)&data, 1, 100);
}

uint8_t SPIReadFpD(void)
{
	uint8_t data = 0x00;

	HAL_SPI_Receive(&hspi2, (uint8_t *)&data, 1, 100);

	return data;
}



