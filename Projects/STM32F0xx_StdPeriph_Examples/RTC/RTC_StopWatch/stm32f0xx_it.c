/**
  ******************************************************************************
  * @file    RTC/RTC_StopWatch/stm32f0xx_it.c 
  * @author  MCD Application Team
  * @version V1.6.0
  * @date    13-October-2021
  * @brief   Main Interrupt Service Routines.
  *          This file provides template for all exceptions handler and 
  *          peripherals interrupt service routine.
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

/* Includes ------------------------------------------------------------------*/
#include "stm32f0xx_it.h"

/** @addtogroup STM32F0xx_StdPeriph_Examples
  * @{
  */

/** @addtogroup RTC_StopWatch
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
extern __IO uint8_t Button_State;
extern __IO uint8_t Button_RTC;
extern __IO uint8_t StartEvent;
extern uint32_t BackupIndex;
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/

/******************************************************************************/
/*            Cortex-M0 Processor Exceptions Handlers                         */
/******************************************************************************/

/**
  * @brief  This function handles NMI exception.
  * @param  None
  * @retval None
  */
void NMI_Handler(void)
{
}

/**
  * @brief  This function handles Hard Fault exception.
  * @param  None
  * @retval None
  */
void HardFault_Handler(void)
{
  /* Go to infinite loop when Hard Fault exception occurs */
  while (1)
  {
  }
}

/**
  * @brief  This function handles SVCall exception.
  * @param  None
  * @retval None
  */
void SVC_Handler(void)
{
}

/**
  * @brief  This function handles PendSVC exception.
  * @param  None
  * @retval None
  */
void PendSV_Handler(void)
{
}

/**
  * @brief  This function handles SysTick Handler.
  * @param  None
  * @retval None
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F0xx Peripherals Interrupt Handlers                   */
/******************************************************************************/
#ifdef USE_STM320518_EVAL
/**
* @brief  This function handles External lines 15 to 4 interrupt request.
* @param  None
* @retval None
*/
void EXTI4_15_IRQHandler(void)
{
  if((EXTI_GetITStatus(LEFT_BUTTON_EXTI_LINE) != RESET) && (StartEvent == 0x0))
    {
      Button_State = LEFT_ON;
    }
    
    else if((EXTI_GetITStatus(RIGHT_BUTTON_EXTI_LINE) != RESET) && (StartEvent !=0x0) && (BackupIndex < 11))
    {
      Button_State = RIGHT_ON;
    }
        /* Clear the LEFT EXTI  pending bit */
      EXTI_ClearITPendingBit(LEFT_BUTTON_EXTI_LINE);  
        /* Clear the RIGHT EXTI line */
      EXTI_ClearITPendingBit(RIGHT_BUTTON_EXTI_LINE);  
}
#else 
/**
* @brief  This function handles External lines 3 to 2 interrupt request.
* @param  None
* @retval None
*/
void EXTI2_3_IRQHandler(void)
{
  if((EXTI_GetITStatus(LEFT_BUTTON_EXTI_LINE) != RESET) && (StartEvent == 0x0))
    {
      Button_State = LEFT_ON;
    }
    
    else if((EXTI_GetITStatus(RIGHT_BUTTON_EXTI_LINE) != RESET) && (StartEvent !=0x0) && (BackupIndex < 11))
    {
      Button_State = RIGHT_ON;
    }
        /* Clear the LEFT EXTI  pending bit */
      EXTI_ClearITPendingBit(LEFT_BUTTON_EXTI_LINE);  
        /* Clear the RIGHT EXTI line */
      EXTI_ClearITPendingBit(RIGHT_BUTTON_EXTI_LINE);  
}
#endif /* USE_STM320518_EVAL */


/**
* @brief  This function handles Tamper pin interrupt request.
* @param  None
* @retval None
*/
void RTC_IRQHandler(void)
{
  if (RTC_GetITStatus(RTC_IT_TAMP1) != RESET)
  {
    Button_RTC = RTC_TAMP;
  }
  /* Clear EXTI line 19 */
  EXTI_ClearITPendingBit(EXTI_Line19);
  /* Clear Tamper pin interrupt pending bit */
  RTC_ClearITPendingBit(RTC_IT_TAMP1);
}
/******************************************************************************/
/*                 STM32F0xx Peripherals Interrupt Handlers                   */
/*  Add here the Interrupt Handler for the used peripheral(s) (PPP), for the  */
/*  available peripheral interrupt handler's name please refer to the startup */
/*  file (startup_stm32f0xx.s).                                               */
/******************************************************************************/

/**
  * @brief  This function handles PPP interrupt request.
  * @param  None
  * @retval None
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */

/**
  * @}
  */

