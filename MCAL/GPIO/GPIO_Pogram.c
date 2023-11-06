/*
 * GPIO_Pogram.c
 *
 *  Created on: Nov 5, 2023
 *      Author: zaher
 */


#include "../Inc/GPIO_Interface.h"
#include "../Inc/GPIO_Private.h"
void GPIO_VidSetPinDirection( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Mode ){

	switch(Copy_u8Port){
	case GPIOA:

		if(Copy_u8Pin <= 7 ){//low

			GPIO_A->CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ));// R M W
			GPIO_A->CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );

		}else if(Copy_u8Pin <=15 ){//high

			Copy_u8Pin = Copy_u8Pin - 8;
			GPIO_A->CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIO_A->CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 );
		}

		break;

	case GPIOB:

		if(Copy_u8Pin <= 7 ){//low

			GPIO_B->CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
			GPIO_B->CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;

		}else if(Copy_u8Pin <=15 ){//high

			Copy_u8Pin = Copy_u8Pin - 8;
			GPIO_B->CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIO_B->CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}

		break;
	case GPIOC:

		if(Copy_u8Pin <= 7 ){//low

			GPIO_C->CRL &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );// R M W
			GPIO_C->CRL |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;

		}else if(Copy_u8Pin <=15 ){//high

			Copy_u8Pin = Copy_u8Pin - 8;
			GPIO_C->CRH &= ~ ( ( 0b1111 )    << ( Copy_u8Pin * 4 ) );
			GPIO_C->CRH |= ( u8Copy_u8Mode ) << ( Copy_u8Pin * 4 )  ;
		}

		break;
	default :break;
	}


}
void GPIO_VidSetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Value ){

	switch(Copy_u8Port){
	case GPIOA:

		if( u8Copy_u8Value == HIGH ){

			SET_BIT( GPIO_A->ODR , Copy_u8Pin );

		}else if( u8Copy_u8Value == LOW ){
			CLEAR_BIT( GPIO_A->ODR , Copy_u8Pin );
		}

		break;
	case GPIOB:

		if( u8Copy_u8Value == HIGH ){

			SET_BIT( GPIO_B->ODR , Copy_u8Pin );

		}else if( u8Copy_u8Value == LOW ){
			CLEAR_BIT( GPIO_B->ODR , Copy_u8Pin );
		}

		break;
	case GPIOC:

		if( u8Copy_u8Value == HIGH ){

			SET_BIT( GPIO_C->ODR , Copy_u8Pin );

		}else if( u8Copy_u8Value == LOW ){
			CLEAR_BIT( GPIO_C->ODR , Copy_u8Pin );
		}

		break;

	}

}
u8   GPIO_u8GetPinValue( u8 Copy_u8Port , u8 Copy_u8Pin ){

	u8 LOC_u8Result = 0 ;

	switch(Copy_u8Port){
	case GPIOA:

		LOC_u8Result = GET_BIT( GPIO_A->IDR , Copy_u8Pin );

		break;
	case GPIOB:

		LOC_u8Result = GET_BIT( GPIO_B->IDR , Copy_u8Pin );

		break;
	case GPIOC:

		LOC_u8Result = GET_BIT( GPIO_C->IDR , Copy_u8Pin );

		break;

	}

	return LOC_u8Result;

}
