/**
  Generated main.c file from MPLAB Code Configurator

  @Company
    Microchip Technology Inc.

  @File Name
    main.c

  @Summary
    This is the generated main.c using PIC24 / dsPIC33 / PIC32MM MCUs.

  @Description
    This source file provides main entry point for system initialization and application code development.
    Generation Information :
        Product Revision  :  PIC24 / dsPIC33 / PIC32MM MCUs - 1.169.0
        Device            :  dsPIC33CK256MP202
    The generated drivers are tested against the following:
        Compiler          :  XC16 v1.50
        MPLAB 	          :  MPLAB X v5.40
*/

/*
    (c) 2020 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
*/

/**
  Section: Included Files
*/
#include "mcc_generated_files/system.h"
#include "mcc_generated_files/uart1.h"
#include "mcc_generated_files/pin_manager.h"
#include "mcc_generated_files/spi1.h"
#include "mcc_generated_files/adc1.h"

inline void delay10()
{
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
    Nop();
}


/*
                         Main application
 */

uint8_t x = 0;
uint8_t i = 0;
uint8_t j = 0;
uint8_t uart1 = 0;
uint8_t uart2 = 0;
uint16_t ramStat[8] = {0,0,0,0,0,0,0,0};
uint16_t flashStat[8] = {0,0,0,0,0,0,0,0};
uint16_t StatCmd[8] = {0x05,0,0,0,0,0,0,0};
uint16_t ana_read[6] = {0,0,0,0,0,0};

uint16_t ReadStat_CMD = 0x0005;

uint16_t temp = 0;

int main(void)
{
    // initialize the device 
    SYSTEM_Initialize();
    SPI1_Initialize();
    csFlash0_SetHigh();
    Nop();
    csFlash0_SetLow();
    Nop();
    csFlash0_SetHigh();
    csFlash1_SetHigh();
    csFlash2_SetHigh();
    csRam0_SetHigh();
    Nop();
    csRam0_SetLow();
    Nop();
    csRam0_SetHigh();
    
    while (1)
    {
        x++;
        if (UART1_IsRxReady())
        {
            uart1 = UART1_Read();
        }
        /*
        csRam0_SetLow();
        Nop();
        Nop();
        Nop();
        SPI1BUFL = ReadStat_CMD;
        Nop();
        SPI1BUFL = 0x0F0F;
        while (SPI1STATLbits.SPIBUSY == 1)
        {
            Nop();
        }
        ramStat[0] = SPI1BUFL;
        Nop();
        ramStat[1] = SPI1BUFL;
        csRam0_SetHigh();
        
        csFlash0_SetLow();
        Nop();
        Nop();
        Nop();
        Nop();
        SPI1BUFL = ReadStat_CMD;
        Nop();
        SPI1BUFL = 0xF0F0;
        while (SPI1STATLbits.SPIBUSY == 1)
        {
            Nop();
        }
        flashStat[0] = SPI1BUFL;
        Nop();
        flashStat[1] = SPI1BUFL;
        csFlash0_SetHigh();
        
         * 
         * */
        ADC1_SoftwareTriggerEnable();
        while (!(ADSTATLbits.AN0RDY & ADSTATLbits.AN1RDY & ADSTATLbits.AN9RDY & ADSTATLbits.AN3RDY & ADSTATLbits.AN4RDY))
        {
            Nop();
        }
        ana_read[0] = ADCBUF0;
        ana_read[1] = ADCBUF1;
        ana_read[2] = ADCBUF9;
        ana_read[3] = ADCBUF3;
        ana_read[4] = ADCBUF4;
        
        printf(ana_read[0]);
        printf(" | ");
        delay10();
        printf(ana_read[1]);
        printf(" | ");
        delay10();
        printf(ana_read[2]);
        printf(" | ");
        delay10();
        printf(ana_read[3]);
        printf(" | ");
        delay10();
        printf(ana_read[4]);
        printf("\r\n");
        delay10();
    }
    return 1; 
}
/**1
 End of File
*/

