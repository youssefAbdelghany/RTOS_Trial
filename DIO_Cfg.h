/*
 * DIO_Cfg.h
 */

#ifndef DIO_CFG_H_
#define DIO_CFG_H_


#define RCGCGPIO *( (volatile u32*) (0x400FE000+0x608))
#define GPIO_PORTF 0x40025000UL
#define GPIODATA *( (volatile u32*) ( GPIO_PORTF+0x3fc))
#define GPIODIR *( (volatile u32*) ( GPIO_PORTF+0x400))
#define GPIOAFSEL *( (volatile u32*) ( GPIO_PORTF+0x420))
#define GPIODEN *( (volatile u32*) ( GPIO_PORTF+0x51C))
#define GPIOAMSEL *( (volatile u32*) ( GPIO_PORTF+0x528))



#endif /* DIO_CFG_H_ */
