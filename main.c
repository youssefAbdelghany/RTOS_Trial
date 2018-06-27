
#include "Std_Types.h"
#include "Utils.h"
#include"DIO_Cfg.h"
#include "FreeRTOS.h"
#include "task.h"
#include "FreeRTOSConfig.h"



/* Define Tasks Priorities */
#define  TASK1_PRIORITY (2)
#define  TASK2_PRIORITY (3)

/*tasks codes prototypes */
 void task1_code(void*pvParamter);
 void task2_code(void*pvParamter);
int x=2;
void main(void)
{

    /*initialize for LED*/
    /*enable clock for portf*/
SET_BIT(RCGCGPIO,5);
/*clear alternative function (msh shghal uart aw ay haga )*/
GPIOAFSEL = 0;
/*clear analog off */
GPIOAMSEL = 0;
/*set digitl on*/
GPIODEN=0xFF;
/*direction of pins*/
GPIODIR=0xFF;


  /*initialize all modules 3mtn */

    /*Creat tasks*/
    xTaskCreate(task1_code,NULL,80,NULL,TASK1_PRIORITY,NULL);
    xTaskCreate(task2_code,NULL,80,NULL,TASK2_PRIORITY,NULL);
    /*start Scheduler */
    vTaskStartScheduler();
while(1)
  {

  }


}




 /*Task1 Code */
  void task1_code(void*pvParamter)  //task w esm el task w ptr to void
 {
        /*AY HAGA TTKTB HENA HATTNFZ MARRA WA7DA FEL TASK 3SHAN LMA BD5OL WHILE EL RTOS LMA BY2T3 D HAYRO7 3LA WHILE 2 EL TNYA
         * BS MSH HAYFZ AY HAGA HENA TANY */

      TickType_t xLastWakeTime;
   // const portTickType xPeriod = pdMS_TO_TICKS( 200 );
    xLastWakeTime = xTaskGetTickCount();
     while(1)  // kol task shayfa el RAM wel uP bto3ha
     {
         GPIODATA=0;
         vTaskDelayUntil( &xLastWakeTime,1000 );
     }
 }

 /*Task 2 Code*/
  void task2_code(void*pvParamter)
 {

      TickType_t xLastWakeTime;
      // const portTickType xPeriod = pdMS_TO_TICKS( 100 );
       xLastWakeTime = xTaskGetTickCount();
     while(1)
     {
         GPIODATA=x;
         x+=2;
         if(x>6)
         {
             x=2;
         }
         vTaskDelayUntil( &xLastWakeTime, 300 );
     }
 }
