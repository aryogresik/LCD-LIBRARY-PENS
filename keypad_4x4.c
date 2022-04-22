// this file modified by eka prasetyono november 2015
// Program study electro intrustry engineering
// eka@pens.ac.id

#include "stm32f4xx_hal.h"

//*** <<< Use Configuration Wizard in Context Menu >>> ***
//
//========== Keypad Configuration
// <e0> Keypad 4x4 Configuration <by eka>
//   <o1.0..2> Keypad DATA PORT
//     <i> Default: KEYPAD_PORT = GPIOE
//        <0=> GPIOA (sometimes used for ADC)
//        <1=> GPIOB (set as the alternate function of JTAG pin)
//        <2=> GPIOC (only for Chip 64 pin and above)
//        <3=> GPIOD (only for Chip 100 pin and above)
//        <4=> GPIOE (only for Chip 100 pin and above)
//        <5=> GPIOF (only for Chip 100 pin and above)
//        <6=> GPIOG (only for Chip 144 pin and above)
//   <o2.0..15> Keypad Kolom 0
//     <i> Default: K0_BIT = Bit 8 
//		  <0x0001=> K0 = Bit 0
//		  <0x0002=> K0 = Bit 1
//		  <0x0004=> K0 = Bit 2
//		  <0x0008=> K0 = Bit 3
//		  <0x0010=> K0 = Bit 4
//		  <0x0020=> K0 = Bit 5
//		  <0x0040=> K0 = Bit 6
//		  <0x0080=> K0 = Bit 7
//		  <0x0100=> K0 = Bit 8
//		  <0x0200=> K0 = Bit 9
//		  <0x0400=> K0 = Bit 10
//		  <0x0800=> K0 = Bit 11
//		  <0x1000=> K0 = Bit 12
//		  <0x2000=> K0 = Bit 13
//		  <0x4000=> K0 = Bit 14
//		  <0x8000=> K0 = Bit 15
//   <o3.0..15> Keypad Kolom 1
//     <i> Default: K1_BIT = Bit 9 
//		  <0x0001=> K1 = Bit 0
//		  <0x0002=> K1 = Bit 1
//		  <0x0004=> K1 = Bit 2
//		  <0x0008=> K1 = Bit 3
//		  <0x0010=> K1 = Bit 4
//		  <0x0020=> K1 = Bit 5
//		  <0x0040=> K1 = Bit 6
//		  <0x0080=> K1 = Bit 7
//		  <0x0100=> K1 = Bit 8
//		  <0x0200=> K1 = Bit 9
//		  <0x0400=> K1 = Bit 10
//		  <0x0800=> K1 = Bit 11
//		  <0x1000=> K1 = Bit 12
//		  <0x2000=> K1 = Bit 13
//		  <0x4000=> K1 = Bit 14
//		  <0x8000=> K1 = Bit 15
//   <o4.0..15> Keypad Kolom 2
//     <i> Default: K2_BIT = Bit 10 
//		  <0x0001=> K2 = Bit 0
//		  <0x0002=> K2 = Bit 1
//		  <0x0004=> K2 = Bit 2
//		  <0x0008=> K2 = Bit 3
//		  <0x0010=> K2 = Bit 4
//		  <0x0020=> K2 = Bit 5
//		  <0x0040=> K2 = Bit 6
//		  <0x0080=> K2 = Bit 7
//		  <0x0100=> K2 = Bit 8
//		  <0x0200=> K2 = Bit 9
//		  <0x0400=> K2 = Bit 10
//		  <0x0800=> K2 = Bit 11
//		  <0x1000=> K2 = Bit 12
//		  <0x2000=> K2 = Bit 13
//		  <0x4000=> K2 = Bit 14
//		  <0x8000=> K2 = Bit 15
//   <o5.0..15> Keypad Kolom 3
//     <i> Default: K3_BIT = Bit 11 
//		  <0x0001=> K3 = Bit 0
//		  <0x0002=> K3 = Bit 1
//		  <0x0004=> K3 = Bit 2
//		  <0x0008=> K3 = Bit 3
//		  <0x0010=> K3 = Bit 4
//		  <0x0020=> K3 = Bit 5
//		  <0x0040=> K3 = Bit 6
//		  <0x0080=> K3 = Bit 7
//		  <0x0100=> K3 = Bit 8
//		  <0x0200=> K3 = Bit 9
//		  <0x0400=> K3 = Bit 10
//		  <0x0800=> K3 = Bit 11
//		  <0x1000=> K3 = Bit 12
//		  <0x2000=> K3 = Bit 13
//		  <0x4000=> K3 = Bit 14
//		  <0x8000=> K3 = Bit 15
//   <o6.0..15> Keypad Baris 0
//     <i> Default: B0_BIT = Bit 12 
//		  <0x0001=> B0 = Bit 0
//		  <0x0002=> B0 = Bit 1
//		  <0x0004=> B0 = Bit 2
//		  <0x0008=> B0 = Bit 3
//		  <0x0010=> B0 = Bit 4
//		  <0x0020=> B0 = Bit 5
//		  <0x0040=> B0 = Bit 6
//		  <0x0080=> B0 = Bit 7
//		  <0x0100=> B0 = Bit 8
//		  <0x0200=> B0 = Bit 9
//		  <0x0400=> B0 = Bit 10
//		  <0x0800=> B0 = Bit 11
//		  <0x1000=> B0 = Bit 12
//		  <0x2000=> B0 = Bit 13
//		  <0x4000=> B0 = Bit 14
//		  <0x8000=> B0 = Bit 15
//   <o7.0..15> Keypad Baris 1
//     <i> Default: B1_BIT = Bit 13 
//		  <0x0001=> B1 = Bit 0
//		  <0x0002=> B1 = Bit 1
//		  <0x0004=> B1 = Bit 2
//		  <0x0008=> B1 = Bit 3
//		  <0x0010=> B1 = Bit 4
//		  <0x0020=> B1 = Bit 5
//		  <0x0040=> B1 = Bit 6
//		  <0x0080=> B1 = Bit 7
//		  <0x0100=> B1 = Bit 8
//		  <0x0200=> B1 = Bit 9
//		  <0x0400=> B1 = Bit 10
//		  <0x0800=> B1 = Bit 11
//		  <0x1000=> B1 = Bit 12
//		  <0x2000=> B1 = Bit 13
//		  <0x4000=> B1 = Bit 14
//		  <0x8000=> B1 = Bit 15
//   <o8.0..15> Keypad Baris 2
//     <i> Default: B2_BIT = Bit 14 
//		  <0x0001=> B2 = Bit 0
//		  <0x0002=> B2 = Bit 1
//		  <0x0004=> B2 = Bit 2
//		  <0x0008=> B2 = Bit 3
//		  <0x0010=> B2 = Bit 4
//		  <0x0020=> B2 = Bit 5
//		  <0x0040=> B2 = Bit 6
//		  <0x0080=> B2 = Bit 7
//		  <0x0100=> B2 = Bit 8
//		  <0x0200=> B2 = Bit 9
//		  <0x0400=> B2 = Bit 10
//		  <0x0800=> B2 = Bit 11
//		  <0x1000=> B2 = Bit 12
//		  <0x2000=> B2 = Bit 13
//		  <0x4000=> B2 = Bit 14
//		  <0x8000=> B2 = Bit 15
//   <o9.0..15> Keypad Baris 3
//     <i> Default: B3_BIT = Bit 15 
//		  <0x0001=> B3 = Bit 0
//		  <0x0002=> B3 = Bit 1
//		  <0x0004=> B3 = Bit 2
//		  <0x0008=> B3 = Bit 3
//		  <0x0010=> B3 = Bit 4
//		  <0x0020=> B3 = Bit 5
//		  <0x0040=> B3 = Bit 6
//		  <0x0080=> B3 = Bit 7
//		  <0x0100=> B3 = Bit 8
//		  <0x0200=> B3 = Bit 9
//		  <0x0400=> B3 = Bit 10
//		  <0x0800=> B3 = Bit 11
//		  <0x1000=> B3 = Bit 12
//		  <0x2000=> B3 = Bit 13
//		  <0x4000=> B3 = Bit 14
//		  <0x8000=> B3 = Bit 15
// </e> End of keypad Configuration
//*** <<< end of configuration section >>>    ***

#define __KEYPAD_4X4    					1              //  harus 1
#define __KEYPAD_PORT		0x000000004              //  port keypad
#define __K0_BIT        0x000000100              //  posisi bit kolom 0 
#define __K1_BIT        0x000000200              //  posisi bit kolom 1  
#define __K2_BIT        0x000000400              //  posisi bit kolom 2  
#define __K3_BIT        0x000000800              //  posisi bit kolom 3  
#define __B0_BIT        0x000001000              //  posisi bit baris 0 
#define __B1_BIT        0x000002000              //  posisi bit baris 1  
#define __B2_BIT        0x000004000              //  posisi bit baris 2  
#define __B3_BIT        0x000008000              //  posisi bit baris 3  



// Deklarasikan Port sambungan Keypad 
#if __KEYPAD_4X4
// inisalisasi Keypad  
   
	#if ((__KEYPAD_PORT & 7)==0)	
		#define KEYPAD_PORT		GPIOA
	#elif ((__KEYPAD_PORT & 7)==1)
		#define KEYPAD_PORT   GPIOB
	#elif ((__KEYPAD_PORT & 7)==2)
		#define KEYPAD_PORT   GPIOC
	#elif ((__KEYPAD_PORT & 7)==3)
		#define KEYPAD_PORT   GPIOD
	#elif ((__KEYPAD_PORT & 7)==4)
		#define KEYPAD_PORT   GPIOE
	#elif ((__KEYPAD_PORT & 7)==5)
		#define KEYPAD_PORT   GPIOF
  #elif ((__KEYPAD_PORT & 7)==6)
		#define KEYPAD_PORT   GPIOG
  #endif	

//


void keypad_init(void)
{		
	GPIO_InitTypeDef GPIO_InitStructure; 
	/********************** Init GPIO Keypad *************************/
 	// aktivasi Kolom bit
	GPIO_InitStructure.Pin = __K0_BIT|__K1_BIT|__K2_BIT|__K3_BIT;
  GPIO_InitStructure.Mode = GPIO_MODE_INPUT;
  GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
  GPIO_InitStructure.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(KEYPAD_PORT, &GPIO_InitStructure);
	
	// aktivasi Baris bit
	GPIO_InitStructure.Pin = __B0_BIT|__B1_BIT|__B2_BIT|__B3_BIT;
  GPIO_InitStructure.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStructure.Speed = GPIO_SPEED_HIGH;
  GPIO_InitStructure.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(KEYPAD_PORT, &GPIO_InitStructure);
	
	HAL_GPIO_WritePin(KEYPAD_PORT,__B0_BIT,GPIO_PIN_SET);
	HAL_GPIO_WritePin(KEYPAD_PORT,__B1_BIT,GPIO_PIN_SET);
	HAL_GPIO_WritePin(KEYPAD_PORT,__B2_BIT,GPIO_PIN_SET);
  HAL_GPIO_WritePin(KEYPAD_PORT,__B3_BIT,GPIO_PIN_SET);
/********************** End GPIO LCD ********************/
}


char keypad_get_key_value(void)
{     int key;
			key=' ';
      HAL_GPIO_WritePin(KEYPAD_PORT,__B0_BIT,GPIO_PIN_RESET);
			HAL_Delay(10);
      if(HAL_GPIO_ReadPin(KEYPAD_PORT,__K0_BIT)==0) key = '1'; 
      else if(HAL_GPIO_ReadPin(KEYPAD_PORT,__K1_BIT)==0) key ='2';
      else if(HAL_GPIO_ReadPin(KEYPAD_PORT,__K2_BIT)==0) key ='3';
      else if(HAL_GPIO_ReadPin(KEYPAD_PORT,__K3_BIT)==0) key ='A';
      HAL_GPIO_WritePin(KEYPAD_PORT,__B0_BIT,GPIO_PIN_SET);
      
      HAL_GPIO_WritePin(KEYPAD_PORT,__B1_BIT,GPIO_PIN_RESET);
			HAL_Delay(10);  
      if(HAL_GPIO_ReadPin(KEYPAD_PORT,__K0_BIT)==0) key = '4'; 
      else if(HAL_GPIO_ReadPin(KEYPAD_PORT,__K1_BIT)==0) key ='5';
      else if(HAL_GPIO_ReadPin(KEYPAD_PORT,__K2_BIT)==0) key ='6';
      else if(HAL_GPIO_ReadPin(KEYPAD_PORT,__K3_BIT)==0) key ='B';
      HAL_GPIO_WritePin(KEYPAD_PORT,__B1_BIT,GPIO_PIN_SET);
      
      HAL_GPIO_WritePin(KEYPAD_PORT,__B2_BIT,GPIO_PIN_RESET);
			HAL_Delay(10); 
      if(HAL_GPIO_ReadPin(KEYPAD_PORT,__K0_BIT)==0) key = '7'; 
      else if(HAL_GPIO_ReadPin(KEYPAD_PORT,__K1_BIT)==0) key ='8';
      else if(HAL_GPIO_ReadPin(KEYPAD_PORT,__K2_BIT)==0) key ='9';
      else if(HAL_GPIO_ReadPin(KEYPAD_PORT,__K3_BIT)==0) key ='C';
      HAL_GPIO_WritePin(KEYPAD_PORT,__B2_BIT,GPIO_PIN_SET);
      
      HAL_GPIO_WritePin(KEYPAD_PORT,__B3_BIT,GPIO_PIN_RESET);
			HAL_Delay(10);
      if(HAL_GPIO_ReadPin(KEYPAD_PORT,__K0_BIT)==0) key = '.'; 
      else if(HAL_GPIO_ReadPin(KEYPAD_PORT,__K1_BIT)==0) key ='0';
      else if(HAL_GPIO_ReadPin(KEYPAD_PORT,__K2_BIT)==0) key ='#';
      else if(HAL_GPIO_ReadPin(KEYPAD_PORT,__K3_BIT)==0) key ='D';
      HAL_GPIO_WritePin(KEYPAD_PORT,__B3_BIT,GPIO_PIN_SET);
			return key;
}

#endif
