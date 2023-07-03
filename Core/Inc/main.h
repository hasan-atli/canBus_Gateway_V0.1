/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */
#define _1_SECOND  1000
#define _500_MS    500
#define _100_MS    100
/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define LED_BLINK_Pin GPIO_PIN_13
#define LED_BLINK_GPIO_Port GPIOC
#define CAND_INT_Pin GPIO_PIN_0
#define CAND_INT_GPIO_Port GPIOA
#define CAND_INT_EXTI_IRQn EXTI0_IRQn
#define CS_CAN_D_Pin GPIO_PIN_1
#define CS_CAN_D_GPIO_Port GPIOA
#define RST_CAND_IC_Pin GPIO_PIN_2
#define RST_CAND_IC_GPIO_Port GPIOA
#define RST_CANB_IC_Pin GPIO_PIN_3
#define RST_CANB_IC_GPIO_Port GPIOA
#define CANB_INT_Pin GPIO_PIN_4
#define CANB_INT_GPIO_Port GPIOA
#define CANB_INT_EXTI_IRQn EXTI4_IRQn
#define CS_CAN_B_Pin GPIO_PIN_0
#define CS_CAN_B_GPIO_Port GPIOB
#define CAN_D_LED_Pin GPIO_PIN_1
#define CAN_D_LED_GPIO_Port GPIOB
#define BTN_0_Pin GPIO_PIN_10
#define BTN_0_GPIO_Port GPIOB
#define CAN_B_LED_Pin GPIO_PIN_12
#define CAN_B_LED_GPIO_Port GPIOB
#define CS_CAN_C_Pin GPIO_PIN_8
#define CS_CAN_C_GPIO_Port GPIOA
#define RST_CANC_IC_Pin GPIO_PIN_11
#define RST_CANC_IC_GPIO_Port GPIOA
#define CAN_C_LED_Pin GPIO_PIN_12
#define CAN_C_LED_GPIO_Port GPIOA
#define CANC_INT_Pin GPIO_PIN_15
#define CANC_INT_GPIO_Port GPIOA
#define CANC_INT_EXTI_IRQn EXTI15_10_IRQn
#define CAN_A_LED_Pin GPIO_PIN_3
#define CAN_A_LED_GPIO_Port GPIOB
#define BTN_1_Pin GPIO_PIN_4
#define BTN_1_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
