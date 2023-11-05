/**
  ******************************************************************************
  * @file    RTC/RTC_StopWatch/main.h 
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
#ifdef USE_STM320518_EVAL
  #include "stm320518_eval.h"
  #include "stm320518_eval_lcd.h"
#else 
  #include "stm32072b_eval.h" 
  #include "stm32072b_eval_lcd.h"
#endif /* USE_STM320518_EVAL */
#include <stdio.h>

/* Exported types ------------------------------------------------------------*/
typedef struct {
  uint8_t tab[12];
} Table_TypeDef;
/* Private define ------------------------------------------------------------*/
#define RTC_TAMP    1
#define LEFT_ON     2
#define RIGHT_ON    3
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void RTC_Time_InitDisplay(void);
void RTC_Time_Display(uint8_t Line, __IO uint16_t Colorx, Table_TypeDef timetable);
Table_TypeDef RTC_Get_Time(uint32_t SecondFrac , RTC_TimeTypeDef* RTC_TimeStructure);

#endif /* __MAIN_H */

