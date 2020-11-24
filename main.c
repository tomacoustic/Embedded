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

char x = 0;
char i = 0;
char j = 0;
char uart1 = 0;
char uart2 = 0;
char ramStat[8] = {0,0,0,0,0,0,0,0};
char flashStat[8] = {0,0,0,0,0,0,0,0};
uint16_t ana_read[4] = {0,0,0,0};

int main(void)
{
    // initialize the device 
    SYSTEM_Initialize();
    csFlash0_SetHigh();
    csFlash1_SetHigh();
    csFlash2_SetHigh();
    csRam0_SetHigh();
    
    
    while (1)
    {
        x++;
        if (UART1_IsRxReady())
        {
            uart1 = UART1_Read();
        }
        if (UART2_IsRxReady())
        {
            uart2 = UART2_Read();
        }
        csRam0_SetLow();
        Nop();
        ramStat[0] = SPI1_Exchange8bit(0x05);
        ramStat[1] = SPI1_Exchange8bit(0x00);
        ramStat[2] = SPI1_Exchange8bit(0x00);
        csRam0_SetHigh();
        csFlash0_SetLow();
        Nop();
        flashStat[0] = SPI1_Exchange8bit(0x05);
        flashStat[1] = SPI1_Exchange8bit(0x00);
        flashStat[2] = SPI1_Exchange8bit(0x00);
        csFlash0_SetHigh();
        
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
        
        
        
        
    }
    return 1; 
}
/**1
 End of File
*/
