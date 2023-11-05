/**
  @page truestudio TrueSTUDIO Project Template for STM32F0xx devices
 
  @verbatim
  ******************** (C) COPYRIGHT 2014 STMicroelectronics *******************
  * @file    readme.txt
  * @author  MCD Application Team
  * @version V1.6.0
  * @date    13-October-2021
  * @brief   This sub-directory contains all the user-modifiable files needed to
  *          create a new project linked with the STM32F0xx Standard Peripherals
  *          Library and working with TrueSTUDIO software toolchain.
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
  @endverbatim
 
 @par Directory contents
 
 - .cproject/.project: A pre-configured project file with the provided library
                       structure that produces an executable image with TrueSTUDIO.

 - stm32_flash.ld:     This file is the TrueSTUDIO linker script used to 
                       place program code (readonly) in internal FLASH and
                       data (readwrite, Stack and Heap)in internal SRAM. 
                       You can customize this file to your need.
                                                          
 @par How to use it ?

 - Open the TrueSTUDIO toolchain.
 - Click on File->Switch Workspace->Other and browse to TrueSTUDIO workspace 
   directory.
 - Click on File->Import, select General->'Existing Projects into Workspace' 
   and then click "Next". 
 - Browse to the TrueSTUDIO workspace directory and select the project: 
   - STM32F051: to configure the project for STM32F051 devices.
   - STM32F031: to configure the project for STM32F031 devices.
   - STM32F030: to configure the project for STM32F030 devices.
   - STM32F072: to configure the project for STM32F072 devices.
   - STM32F042: to configure the project for STM32F042 devices.
   - STM32F091: to configure the project for STM32F091 devices.
   - STM32F030xC: to configure the project for STM32F030xC devices.
   - STM32F070xB: to configure the project for STM32F070xB devices.
   - STM32F070x6: to configure the project for STM32F070x6 devices.
 - Rebuild all project files: Select the project in the "Project explorer" 
   window then click on Project->build project menu.
 - Run program: Select the project in the "Project explorer" window then click 
   Run->Debug (F11)

 @note The needed define symbols for this config are already declared in the
       preprocessor section. 

 */

