/**
  ******************************************************************************
  * @file    stm32072b_eval_i2c_tsensor.h
  * @author  MCD Application Team
  * @version V1.0.1
  * @date    13-October-2021
  * @brief   This file contains all the functions prototypes for the 
  *          stm32072b_eval_i2c_tsensor.c firmware driver.
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
#ifndef __STM32072B_EVAL_I2C_TSENSOR_H
#define __STM32072B_EVAL_I2C_TSENSOR_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32072b_eval.h"

/** @addtogroup Utilities
  * @{
  */
  
/** @addtogroup STM32_EVAL
  * @{
  */ 

/** @addtogroup STM32072B_EVAL
  * @{
  */
  
/** @addtogroup STM32072B_EVAL_I2C_TSENSOR
  * @{
  */  
/* Exported types ------------------------------------------------------------*/   
/** 
  * @brief  TSENSOR Status  
  */ 
typedef enum
{
  LM75_OK = 0,
  LM75_FAIL
}LM75_Status_TypDef;

/* Exported constants --------------------------------------------------------*/
/* Uncomment the following line to use Timeout_User_Callback LM75_TimeoutUserCallback(). 
   If This Callback is enabled, it should be implemented by user in main function .
   LM75_TimeoutUserCallback() function is called whenever a timeout condition 
   occurs during communication (waiting on an event that doesn't occur, bus 
   errors, busy devices ...). */   
/* #define USE_TIMEOUT_USER_CALLBACK */    
    
/* Maximum Timeout values for flags and events waiting loops. These timeouts are
   not based on accurate values, they just guarantee that the application will 
   not remain stuck if the I2C communication is corrupted.
   You may modify these timeout values depending on CPU frequency and application
   conditions (interrupts routines ...). */   
#define LM75_FLAG_TIMEOUT         ((uint32_t)0x1000)
#define LM75_LONG_TIMEOUT         ((uint32_t)(10 * LM75_FLAG_TIMEOUT))    
    

/**
  * @brief  Block Size
  */
#define LM75_REG_TEMP       0x00  /*!< Temperature Register of LM75 */
#define LM75_REG_CONF       0x01  /*!< Configuration Register of LM75 */
#define LM75_REG_THYS       0x02  /*!< Temperature Register of LM75 */
#define LM75_REG_TOS        0x03  /*!< Over-temp Shutdown threshold Register of LM75 */
#define I2C_TIMEOUT         ((uint32_t)0x3FFFF) /*!< I2C Time out */
#define LM75_ADDR           0x90   /*!< LM75 address */


#define LM75_I2C_TIMING     0x1045061D
   
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */ 
void LM75_DeInit(void);
void LM75_Init(void);
ErrorStatus LM75_GetStatus(void);
uint16_t LM75_ReadTemp(void);
uint16_t LM75_ReadReg(uint8_t RegName);
uint8_t LM75_WriteReg(uint8_t RegName, uint16_t RegValue);
uint8_t LM75_ReadConfReg(void);
uint8_t LM75_WriteConfReg(uint8_t RegValue);
uint8_t LM75_ShutDown(FunctionalState NewState);

/** 
  * @brief  Timeout user callback function. This function is called when a timeout
  *         condition occurs during communication with LM75. Only protoype
  *         of this function is decalred in LM75 driver. Its implementation
  *         may be done into user application. This function may typically stop
  *         current operations and reset the I2C peripheral and LM75.
  *         To enable this function use uncomment the define USE_TIMEOUT_USER_CALLBACK
  *         at the top of this file.          
  */
#ifdef USE_TIMEOUT_USER_CALLBACK 
 uint8_t LM75_TIMEOUT_UserCallback(void);
#else
 #define LM75_TIMEOUT_UserCallback()  LM75_FAIL
#endif /* USE_TIMEOUT_USER_CALLBACK */
 
#ifdef __cplusplus
}
#endif

#endif /* __STM32072B_EVAL_I2C_TSENSOR_H */

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */ 

/**
  * @}
  */

