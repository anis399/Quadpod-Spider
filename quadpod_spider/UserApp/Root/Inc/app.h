/***************************************************************************//**
 * @file
 * @brief Top level application functions
 *******************************************************************************
 * # License
 * <b>Copyright 2020 Silicon Laboratories Inc. www.silabs.com</b>
 *******************************************************************************
 *
 * The licensor of this software is Silicon Laboratories Inc. Your use of this
 * software is governed by the terms of Silicon Labs Master Software License
 * Agreement (MSLA) available at
 * www.silabs.com/about-us/legal/master-software-license-agreement. This
 * software is distributed to you in Source Code format and is governed by the
 * sections of the MSLA applicable to Source Code.
 *
 ******************************************************************************/

/******************************************************************************
 * Multiple include protection
 *****************************************************************************/
#ifndef APP_H
#define APP_H

/******************************************************************************
 * Includes
 *****************************************************************************/
//System
#include "em_chip.h"
#include "em_device.h"
#include "em_cmu.h"
#include "em_emu.h"
#include "em_system.h"
#include "math.h"

//Components
#include "ustimer.h"                    // Using timer4 for delay function
#include "sl_iostream_init_instances.h" //IOSTREM for debug
#include "printf.h"                     //Component "Tiny printf"

//Peripherals
#include "PWM.h"

/******************************************************************************
 * Macros
 *****************************************************************************/

/******************************************************************************
 * Defines
 *****************************************************************************/

/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void);

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void);

#endif  // APP_H
