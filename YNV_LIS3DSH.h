/*
 * YNV_LIS3DSH.h
 *
 *  Created on: Jan 17, 2021
 *      Author: aorqu
 */

#ifndef INC_YNV_LIS3DSH_H_
#define INC_YNV_LIS3DSH_H_

#include "stm32f4xx_hal.h"
#include <math.h>
#include <stdio.h>
#include <string.h>



/*register adress*/

//CTRL_REG4
#define LIS3DSH_CTRLREG4_ADDR	0x20
#define LIS3DSH_CTRLREG4_ODR	((uint8_t)0x30)		//ODR 12,5Hz
#define LIS3DSH_CTRLREG4_XEN	((uint8_t)0x01)		//X enable
#define LIS3DSH_CTRLREG4_YEN	((uint8_t)0x02)		//Y enable
#define LIS3DSH_CTRLREG4_ZEN	((uint8_t)0x04)		//Z enable
#define LIS3DSH_BDU		((uint8_t)0x08)		//BDU activate => don't update data when aren't read

//CTRL_REG5
#define LIS3DSH_CTRLREG5_ADDR	0x24
//Full scale
#define LIS3DSH_CTRLREG5_2G		((uint8_t)0x00)
#define LIS3DSH_CTRLREG5_4G		((uint8_t)0x08)
#define LIS3DSH_CTRLREG5_6G		((uint8_t)0x10)
#define LIS3DSH_CTRLREG5_8G		((uint8_t)0x18)
#define LIS3DSH_CTRLREG5_16G		((uint8_t)0x20)


//OUT_X
#define LIS3DSH_OUT_X_L_ADDR	0x28
#define LIS3DSH_OUT_X_H_ADDR	0x29

//OUT_Y
#define LIS3DSH_OUT_Y_L_ADDR	0x2A
#define LIS3DSH_OUT_Y_H_ADDR	0x2B

//LED
#define LED_ORANGE_ON			((uint8_t)0x01)
#define LED_VERTE_ON			((uint8_t)0x01)
#define LED_ROUGE_ON			((uint8_t)0x01)
#define LED_BLEU_ON				((uint8_t)0x01)

#define LED_ORANGE_OFF			((uint8_t)0x00)
#define LED_VERTE_OFF			((uint8_t)0x00)
#define LED_ROUGE_OFF			((uint8_t)0x00)
#define LED_BLEU_OFF			((uint8_t)0x00)



/*init struct*/
typedef struct
{

	float accX;
	float accY;

	uint8_t fScaleSelec;
	uint8_t bdu;
	uint8_t odr;
	uint8_t xenable;
	uint8_t yenable;

}LIS3DSH_init_t;


typedef enum
{
	LIS3DSH_OK,
	LIS3DSH_ERROR
}LIS3DSH_Status_t;


/*Write function*/
LIS3DSH_Status_t LIS3DSH_Write_Reg(	SPI_HandleTypeDef *hspi,
									uint8_t reg_addr,
									uint8_t *dataW,
									uint8_t size);

/*Read function*/
LIS3DSH_Status_t LIS3DSH_Read_Reg(	SPI_HandleTypeDef *hspi,
									uint8_t reg_addr,
									uint8_t *dataR,
									uint8_t size);

/*init function*/
LIS3DSH_Status_t LIS3DSH_Init_Reg(	SPI_HandleTypeDef *hspi,
									LIS3DSH_init_t *initDef);

LIS3DSH_Status_t LIS3DSH_Get_Position(SPI_HandleTypeDef *hspi, LIS3DSH_init_t *lis3dsh, float pitch, float roll);



#endif /* INC_YNV_LIS3DSH_H_ */
