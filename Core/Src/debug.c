/*
 * debug.c
 *
 *  Created on: Mar 22, 2023
 *      Author: hasan
 */
#include "debug.h"
#include "stm32F1xx_hal.h"
#include "stdarg.h"

extern UART_HandleTypeDef huart1;

void dbgPrintf(char *fmt, ...)
{
  char dbgBuf[256];
  va_list args;
  va_start(args, fmt);
  int rc = vsnprintf(dbgBuf, sizeof(dbgBuf), fmt, args);
  va_end(args);

  HAL_UART_Transmit(&huart1, dbgBuf, strlen(dbgBuf), 10);
}

void dbgPrint(char *str)
{
	HAL_UART_Transmit(&huart1, str, strlen(str), 10);
}

void dbgPrintByte(uint8_t *p_array, uint8_t size)
{
	HAL_UART_Transmit(&huart1, p_array, size, 10);
}
