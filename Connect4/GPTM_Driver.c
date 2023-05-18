#include "GPTM_Driver.h"
#include <stdlib.h>
#include <math.h>
int k;
    volatile unsigned long dummy ;

volatile unsigned long* TIMERS_R[]={&TIMER0_CTL_R,&TIMER1_CTL_R,&TIMER2_CTL_R,                       //Array of CTL Registers for each timer
                               &TIMER3_CTL_R,&TIMER4_CTL_R,&TIMER5_CTL_R};

volatile unsigned long* TIMERS_CFG_R[]={&TIMER0_CFG_R,&TIMER1_CFG_R,&TIMER2_CFG_R,                   //Array of CFG Registers for each timer
                                   &TIMER3_CFG_R,&TIMER4_CFG_R,&TIMER5_CFG_R};

volatile unsigned long* TIMERS_TAMR_R[]={&TIMER0_TAMR_R,&TIMER1_TAMR_R,&TIMER2_TAMR_R,               //Array of TAMR Registers for each timer
                                   &TIMER3_TAMR_R,&TIMER4_TAMR_R,&TIMER5_TAMR_R};

volatile unsigned long* TIMERS_TAPR_R[]={&TIMER0_TAPR_R,&TIMER1_TAPR_R,&TIMER2_TAPR_R,               //Array of TAPR Registers for each timer
                                   &TIMER3_TAPR_R,&TIMER4_TAPR_R,&TIMER5_TAPR_R};

volatile unsigned long* TIMERS_Aload_R[]={&TIMER0_TAILR_R,&TIMER1_TAILR_R,&TIMER2_TAILR_R,           //Array of TAILR Registers for each timer
                                     &TIMER3_TAILR_R,&TIMER4_TAILR_R,&TIMER5_TAILR_R};

volatile unsigned long* TIMERS_Clear_R[]={&TIMER0_ICR_R,&TIMER1_ICR_R,&TIMER2_ICR_R,                 //Array of ICR Registers for each timer
                                     &TIMER3_ICR_R,&TIMER4_ICR_R,&TIMER5_ICR_R};

volatile unsigned long* TIMERS_Flag_R[]={&TIMER0_RIS_R,&TIMER1_RIS_R,&TIMER2_RIS_R,                  //Array of RIS Registers for each timer
                                     &TIMER3_RIS_R,&TIMER4_RIS_R,&TIMER5_RIS_R};



void CLK_Enable_GPTM_Module(int timer_number)                                                   //To Eable CLK for specific timer
{
    SYSCTL_RCGCTIMER_R |= (1UL << timer_number);
for (k = 0; k < 4; k++) {
        __asm__("nop");
    }
	//To wait untill enabling the CLK
}

void Enable_Timer_Number(int timer_number,char type[10])                                        //Enable or Disable a specific timer
{
    if(strcmp(type , "Enable")==0)
        {
        *TIMERS_R[timer_number] |= 1UL << 0;                                                    //To Enable specific timer
        }
    else if (strcmp(type , "Disable")==0)
        {
        *TIMERS_R[timer_number] &= ~(1UL << 0);                                                 //To Disable specific timer
        }
}

void Timer_Number_Option(int timer_number,char option[10])                                      //To select timer option from 16, 32, or RTC
{
    if((strcmp(option,"16"))==0)
        *TIMERS_CFG_R[timer_number] = 0x4;                                                      //16 bits option
    else if((strcmp(option,"32"))==0)
        *TIMERS_CFG_R[timer_number] = 0x0;                                                      //32 bits option
    else if ((strcmp(option,"RTC"))==0)
        *TIMERS_CFG_R[timer_number] = 0x1;                                                      //RTC option
}

void Timer_Number_Mode(int timer_number,char mode[10])                                          //To select timer option from one shot, periodic, or capture
{
    if((strcmp(mode,"one_shot"))==0)
        *TIMERS_TAMR_R[timer_number] |= 0x1;                                                    //One Shot mode
    else if((strcmp(mode,"periodic"))==0)
        *TIMERS_TAMR_R[timer_number] |= 0x2;                                                    //Periodic mode
    else if((strcmp(mode,"capture"))==0)
        *TIMERS_TAMR_R[timer_number] |= 0x3;                                                    //Capture mode
}



void Timer_Number_Ticks(int timer_number,int ticks)                                             //To load Number of ticks
{
	
    *TIMERS_Aload_R[timer_number] = ticks-1;       
for (k;k<500;k++){        __asm__("nop");
}	//Load Ticks
    *TIMERS_Clear_R[timer_number]= 1;        
for (k;k<500;k++){        __asm__("nop");
}//clear timer flag
}

void GPTM_Delay_Unit(int timer_number,int Counts,char Unit[10])                                 //Delay using GPTM  Timer
{
    if((strcmp(Unit,"Seconds"))==0)                                                             //Seconds delay
    {
        Timer_Number_Ticks(timer_number,320000);                                                           //Ticks for one second
        Enable_Timer_Number(timer_number,"Enable");
        for(k=0;k<Counts;k++)
        {
             while((*TIMERS_Flag_R[timer_number] & 0x1)==0);                                    //Number of seconds
             *TIMERS_Clear_R[timer_number]= 1;
        }
    }
    else if((strcmp(Unit,"Millisecond"))==0)                                                    //milliseconds delay
    {
        Timer_Number_Ticks(timer_number,320);                                                              //ticks for one milliseconds
        Enable_Timer_Number(timer_number,"Enable");
        for(k=0;k<Counts;k++)
        {
             while((*TIMERS_Flag_R[timer_number] & 0x1)==0);                                    //Number of milliseconds
             *TIMERS_Clear_R[timer_number]= 1;
        }
    }
}
void TIMER_INIT(int timer_number,int Counts,char Unit[10],char mode[10],char option[10])
{
	CLK_Enable_GPTM_Module(timer_number);  
	Enable_Timer_Number(timer_number,"Disable");                                             //Disable Timer        
  Timer_Number_Option(timer_number,option);                                                  //32 bits Option Timer
  Timer_Number_Mode(timer_number,mode);                                              //Periodic Mode For Timer Module 1
  GPTM_Delay_Unit(timer_number,Counts,Unit); 
}
