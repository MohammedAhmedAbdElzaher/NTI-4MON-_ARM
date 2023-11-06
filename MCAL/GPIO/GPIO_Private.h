/*
 * GPIO_Private.h
 *
 *  Created on: Nov 5, 2023
 *      Author: zaher
 */

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_


typedef  struct
{
	volatile u32 CRL   ;
	volatile u32 CRH   ;
	volatile u32 IDR     ;
	volatile u32 ODR   ;
	volatile u32 BSRR   ;
	volatile u32 BRR   ;
	volatile u32 LCKR   ;

}GPIO;

#define GPIO_C    ((volatile GPIO* )0x40011000)
#define GPIO_B    ((volatile GPIO* )0x40010C00)
#define GPIO_A    ((volatile GPIO* )0x40010800)

#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
