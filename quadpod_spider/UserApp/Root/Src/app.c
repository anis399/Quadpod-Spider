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
 * Includes
 *****************************************************************************/
#include "app.h"

/******************************************************************************
 * Data types
 *****************************************************************************/
volatile uint32_t systick_counter = 0;


Timer_t Timer_Handler_FL = {
    .timer      = TIMER0,
    .frequency  = 50,
};

PWM_Output_t tibia_out = {
    .port  = gpioPortC,
    .pin   = 0,
    .ch    = 0,
    .angle = 90,
};
PWM_Output_t coxa_out = {
    .port  = gpioPortC,
    .pin   = 1,
    .ch    = 1,
    .angle = 90,
};
PWM_Output_t femur_out = {
    .port  = gpioPortC,
    .pin   = 2,
    .ch    = 2,
    .angle = 90,
};

/***************************************************************************//**
 * Initialize application.
 ******************************************************************************/
void app_init(void)
{
  /** Enable SysTick */
  uint32_t returnCode = 1;
  while(returnCode !=0){returnCode = SysTick_Config(SystemCoreClock/1000);}

  /** Initiate usTimer (Timer 4) */
  USTIMER_Init();

  /** Init 3-ch PWM */
  PWM_D_ConfigTimer(&Timer_Handler_FL);
  PWM_D_ConfigCH(&Timer_Handler_FL, &tibia_out, 90);
  PWM_D_ConfigCH(&Timer_Handler_FL, &coxa_out , 90);
  PWM_D_ConfigCH(&Timer_Handler_FL, &femur_out, 90);
  PWM_D_EnableTimer(&Timer_Handler_FL);

}

/***************************************************************************//**
 * App ticking function.
 ******************************************************************************/
void app_process_action(void)
{
  printf("Hello world\n");
  USTIMER_Delay(1000000);

}

/*******************************************************************************
 * Private
 ******************************************************************************/
void SysTick_Handler(void){
  systick_counter++;
  if(!systick_counter){
      systick_counter++;
  }
}
