#include "tm4c123gh6pm.h"
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <math.h>



#ifndef GPTM_Driver_h
#define GPTM_Driver_h


extern void CLK_Enable_GPTM_Module(int timer_number);                                             //To Eable CLK for specific timer
extern void Enable_Timer_Number(int timer_number,char type[10]);                                  //Enable or Disable a specific timer
extern void Timer_Number_Option(int timer_number,char option[10]);                                //To select timer option from 16, 32, or RTC
extern void Timer_Number_Mode(int timer_number,char mode[10]);                                    //To select timer option from one shot, periodic, or capture
extern void Timer_Number_Ticks(int timer_number,int ticks);                                       //To load Number of ticks
extern void GPTM_Delay_Unit(int timer_number,int Counts,char Unit[10]);                           //Delay using GPTM  Timer
extern void TIMER_INIT(int timer_number,int Counts,char Unit[10],char mode[10],char option[10]);  //To use Timer with delay
#endif
