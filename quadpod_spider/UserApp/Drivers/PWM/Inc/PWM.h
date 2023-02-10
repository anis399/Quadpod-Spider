/**********************************************************************************************************************
               ░█████╗░███╗░░██╗██╗░██████╗  ░██████╗██╗░░██╗░█████╗░██╗░░██╗██╗░░██╗░█████╗░██╗░░░██╗██████╗░
               ██╔══██╗████╗░██║██║██╔════╝  ██╔════╝██║░░██║██╔══██╗██║░██╔╝██║░██╔╝██╔══██╗██║░░░██║██╔══██╗
               ███████║██╔██╗██║██║╚█████╗░  ╚█████╗░███████║███████║█████═╝░█████═╝░██║░░██║██║░░░██║██████╔╝
               ██╔══██║██║╚████║██║░╚═══██╗  ░╚═══██╗██╔══██║██╔══██║██╔═██╗░██╔═██╗░██║░░██║██║░░░██║██╔══██╗
               ██║░░██║██║░╚███║██║██████╔╝  ██████╔╝██║░░██║██║░░██║██║░╚██╗██║░╚██╗╚█████╔╝╚██████╔╝██║░░██║
               ╚═╝░░╚═╝╚═╝░░╚══╝╚═╝╚═════╝░  ╚═════╝░╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝╚═╝░░╚═╝░╚════╝░░╚═════╝░╚═╝░░╚═╝

 * File  PWM.h
 *
 *  Created on: Feb 03, 2023
 *  Author: Anis Shakkour
 *  Email:  anis.shakkour399@gmail.com
 ******************************************************************************/
/******************************************************************************
 * Description  : configure 3-PWMs from a single timer.
 *
 *                Used DataSheets: SiLabs AN0014
 *
 * Usage        : This driver is mainly used to drive 12 servos that operate
 *                on PWM. These servos are will power a QuadPod Spider.
 * Known Errors :
 * ToDo         :
 *****************************************************************************/

/******************************************************************************
 * Multiple include protection
 *****************************************************************************/
#ifndef PWM_H_
#define PWM_H_

/******************************************************************************
 * Includes
 *****************************************************************************/
#include "Quadpod_Spider.h"
#include "app.h"

#include "em_cmu.h"
#include "em_timer.h"
#include "em_gpio.h"
#include "math.h"

/******************************************************************************
 * Macros
 *****************************************************************************/
inline int32_t MAX(int32_t a, int32_t b) { return((a) > (b) ? a : b); }
inline int32_t MIN(int32_t a, int32_t b) { return((a) < (b) ? a : b); }

/******************************************************************************
 * Defines
 *****************************************************************************/
#define PWM_FREQ    ((uint8_t)50)                         /** Define PWM frequency value [Hz] */
#define MAX_ANGLE   ((uint8_t)180)
#define MIN_ANGLE   ((uint8_t)0)

/******************************************************************************
 * Typedef & Enums
 *****************************************************************************/

/** PWM - The actual leg which will have contact with the surface */
typedef struct {
  TIMER_TypeDef *timer;                                   /**< Base pointer                                       */
  uint32_t frequency;                                     /**< Units in Hz                                        */
  //uint32_t top_value;                                     /**<                                                    */
} Timer_t;

/** PWM -> Servo motor output */
typedef struct {
  GPIO_Port_TypeDef port;
  unsigned int pin;
  unsigned int ch;
  float angle;
} PWM_Output_t;


/******************************************************************************
 * Interface Functions
 *****************************************************************************/

CMU_Clock_TypeDef PWM_D_get_timer_clock(TIMER_TypeDef *timer);

RetVal_t PWM_D_ConfigTimer(Timer_t *timerP);
RetVal_t PWM_D_ConfigCH(Timer_t *timerP, PWM_Output_t *output, float default_angle);
RetVal_t PWM_D_ConfigAll_CH(Timer_t *timerP, PWM_Output_t *output0, PWM_Output_t *output1, PWM_Output_t *output2);

RetVal_t PWM_D_EnableTimer(Timer_t *timerP);
RetVal_t PWM_D_DisableTimer(Timer_t *timerP);
RetVal_t PWM_D_EnableCH(Timer_t *timerP, PWM_Output_t *output);
RetVal_t PWM_D_DisableCH(Timer_t *timerP, PWM_Output_t *output);

uint32_t PWM_D_angle_to_DC(uint32_t topvalue, float angle);

/******************************************************************************
 * END
 *****************************************************************************/

#endif /* PWM_H_ */
