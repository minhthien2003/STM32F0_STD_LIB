/**
  ******************************************************************************
  * @file    I2C/I2C_TwoBoards/main.h 
  * @author  MCD Application Team
  * @version V1.6.0
  * @date    13-October-2021
  * @brief   Header for main.c module
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2014 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
  
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx.h"
#include "stm32f0xx_i2c_cpal.h"
#ifdef USE_STM320518_EVAL
  #include "stm320518_eval.h"
  #include "stm320518_eval_lcd.h"
#else 
  #include "stm32072b_eval.h"
  #include "stm32072b_eval_lcd.h"
#endif /* USE_STM320518_EVAL */

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/

/* This define select used I2Cx device for communication */

#define I2C_DevStructure        I2C1_DevStructure


#define countof(a) (sizeof(a) / sizeof(*(a)))

#define MESSAGE1                (uint8_t*)"---STM32 CPAL Lib---"
#define MESSAGE2                (uint8_t*)"I2C 2xBoards Example"
#define MESSAGE3                (uint8_t*)"-------READY--------"

#define MEASSAGE_EMPTY          (uint8_t*)"                    "

#define MAX_BUFF_SIZE           200
#define BUFFER_SIZE             (countof(tStateSignal)-1)

#define OWN_ADDRESS             0x74

#define I2C_TIMING              0x00731012 

#define ACTION_NONE             0xFF
#define ACTION_DISABLED         0xFD
#define ACTION_PENDING          0xFE
#define ACTION_PERIODIC         0xFC

#define STATE_OFF               0
#define STATE_ON                1

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

#endif /* __MAIN_H */

