/**
  ADC1 Generated Driver File

  @Company
    Microchip Technology Inc.

  @File Name
    adc1.c

  @Summary
    This is the generated driver implementation file for the ADC1 driver using PIC24 / dsPIC33 / PIC32MM MCUs

  @Description
    This source file provides APIs for ADC1.
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

#include "adc1.h"

/**
 Section: File specific functions
*/

static void (*ADC1_CommonDefaultInterruptHandler)(void);
static void (*ADC1_Mic3DefaultInterruptHandler)(uint16_t adcVal);
static void (*ADC1_SpareAnDefaultInterruptHandler)(uint16_t adcVal);
static void (*ADC1_Mic2DefaultInterruptHandler)(uint16_t adcVal);
static void (*ADC1_Mic0DefaultInterruptHandler)(uint16_t adcVal);
static void (*ADC1_Mic1DefaultInterruptHandler)(uint16_t adcVal);

/**
  Section: Driver Interface
*/

void ADC1_Initialize (void)
{
    // ADSIDL disabled; ADON enabled; 
    ADCON1L = (0x8000 & 0x7FFF); //Disabling ADON bit
    // FORM Fractional; SHRRES 12-bit resolution; 
    ADCON1H = 0xE0;
    // PTGEN disabled; SHRADCS 2; REFCIE disabled; SHREISEL Early interrupt is generated 1 TADCORE clock prior to data being ready; REFERCIE disabled; EIEN disabled; 
    ADCON2L = 0x00;
    // SHRSAMC 248; 
    ADCON2H = 0xF8;
    // SWCTRG disabled; SHRSAMP disabled; SUSPEND disabled; SWLCTRG disabled; SUSPCIE disabled; CNVCHSEL AN0; REFSEL disabled; 
    ADCON3L = 0x00;
    // SHREN enabled; C1EN enabled; C0EN enabled; CLKDIV 1; CLKSEL FOSC/2; 
    ADCON3H = (0x83 & 0xFF00); //Disabling C0EN, C1EN, C2EN, C3EN and SHREN bits
    // SAMC0EN disabled; SAMC1EN disabled; 
    ADCON4L = 0x00;
    // C0CHS AN0; C1CHS ANA1; 
    ADCON4H = 0x04;
    // SIGN0 disabled; SIGN4 disabled; SIGN3 disabled; SIGN2 disabled; SIGN1 disabled; SIGN7 disabled; SIGN6 disabled; DIFF0 disabled; SIGN5 disabled; DIFF1 disabled; DIFF2 disabled; DIFF3 disabled; DIFF4 disabled; DIFF5 disabled; DIFF6 disabled; DIFF7 disabled; 
    ADMOD0L = 0x00;
    // DIFF8 disabled; DIFF9 disabled; SIGN10 disabled; SIGN11 disabled; SIGN8 disabled; DIFF11 disabled; DIFF10 disabled; SIGN9 disabled; 
    ADMOD0H = 0x00;
    // DIFF25 disabled; SIGN25 disabled; 
    ADMOD1H = 0x00;
    // IE1 disabled; IE0 disabled; IE3 disabled; IE2 disabled; IE5 disabled; IE4 disabled; IE10 disabled; IE7 disabled; IE6 disabled; IE9 disabled; IE8 disabled; IE11 disabled; 
    ADIEL = 0x00;
    // IE24 disabled; IE25 disabled; 
    ADIEH = 0x00;
    // CMPEN6 disabled; CMPEN10 disabled; CMPEN5 disabled; CMPEN11 disabled; CMPEN4 disabled; CMPEN3 disabled; CMPEN2 disabled; CMPEN1 disabled; CMPEN0 disabled; CMPEN9 disabled; CMPEN8 disabled; CMPEN7 disabled; 
    ADCMP0ENL = 0x00;
    // CMPEN6 disabled; CMPEN10 disabled; CMPEN5 disabled; CMPEN11 disabled; CMPEN4 disabled; CMPEN3 disabled; CMPEN2 disabled; CMPEN1 disabled; CMPEN0 disabled; CMPEN9 disabled; CMPEN8 disabled; CMPEN7 disabled; 
    ADCMP1ENL = 0x00;
    // CMPEN6 disabled; CMPEN10 disabled; CMPEN5 disabled; CMPEN11 disabled; CMPEN4 disabled; CMPEN3 disabled; CMPEN2 disabled; CMPEN1 disabled; CMPEN0 disabled; CMPEN9 disabled; CMPEN8 disabled; CMPEN7 disabled; 
    ADCMP2ENL = 0x00;
    // CMPEN6 disabled; CMPEN10 disabled; CMPEN5 disabled; CMPEN11 disabled; CMPEN4 disabled; CMPEN3 disabled; CMPEN2 disabled; CMPEN1 disabled; CMPEN0 disabled; CMPEN9 disabled; CMPEN8 disabled; CMPEN7 disabled; 
    ADCMP3ENL = 0x00;
    // CMPEN25 disabled; CMPEN24 disabled; 
    ADCMP0ENH = 0x00;
    // CMPEN25 disabled; CMPEN24 disabled; 
    ADCMP1ENH = 0x00;
    // CMPEN25 disabled; CMPEN24 disabled; 
    ADCMP2ENH = 0x00;
    // CMPEN25 disabled; CMPEN24 disabled; 
    ADCMP3ENH = 0x00;
    // CMPLO 0; 
    ADCMP0LO = 0x00;
    // CMPLO 0; 
    ADCMP1LO = 0x00;
    // CMPLO 0; 
    ADCMP2LO = 0x00;
    // CMPLO 0; 
    ADCMP3LO = 0x00;
    // CMPHI 0; 
    ADCMP0HI = 0x00;
    // CMPHI 0; 
    ADCMP1HI = 0x00;
    // CMPHI 0; 
    ADCMP2HI = 0x00;
    // CMPHI 0; 
    ADCMP3HI = 0x00;
    // OVRSAM 4x; MODE Oversampling Mode; FLCHSEL AN0; IE disabled; FLEN disabled; 
    ADFL0CON = 0x400;
    // OVRSAM 4x; MODE Oversampling Mode; FLCHSEL AN0; IE disabled; FLEN disabled; 
    ADFL1CON = 0x400;
    // OVRSAM 4x; MODE Oversampling Mode; FLCHSEL AN0; IE disabled; FLEN disabled; 
    ADFL2CON = 0x400;
    // OVRSAM 4x; MODE Oversampling Mode; FLCHSEL AN0; IE disabled; FLEN disabled; 
    ADFL3CON = 0x400;
    // HIHI disabled; LOLO disabled; HILO disabled; BTWN disabled; LOHI disabled; CMPEN disabled; IE disabled; 
    ADCMP0CON = 0x00;
    // HIHI disabled; LOLO disabled; HILO disabled; BTWN disabled; LOHI disabled; CMPEN disabled; IE disabled; 
    ADCMP1CON = 0x00;
    // HIHI disabled; LOLO disabled; HILO disabled; BTWN disabled; LOHI disabled; CMPEN disabled; IE disabled; 
    ADCMP2CON = 0x00;
    // HIHI disabled; LOLO disabled; HILO disabled; BTWN disabled; LOHI disabled; CMPEN disabled; IE disabled; 
    ADCMP3CON = 0x00;
    // LVLEN9 disabled; LVLEN8 disabled; LVLEN11 disabled; LVLEN7 disabled; LVLEN10 disabled; LVLEN6 disabled; LVLEN5 disabled; LVLEN4 disabled; LVLEN3 disabled; LVLEN2 disabled; LVLEN1 disabled; LVLEN0 disabled; 
    ADLVLTRGL = 0x00;
    // LVLEN24 disabled; LVLEN25 disabled; 
    ADLVLTRGH = 0x00;
    // SAMC 0; 
    ADCORE0L = 0x00;
    // SAMC 0; 
    ADCORE1L = 0x00;
    // RES 12-bit resolution; EISEL Early interrupt is generated 1 TADCORE clock prior to data being ready; ADCS 2; 
    ADCORE0H = 0x300;
    // RES 12-bit resolution; EISEL Early interrupt is generated 1 TADCORE clock prior to data being ready; ADCS 2; 
    ADCORE1H = 0x300;
    // EIEN9 disabled; EIEN7 disabled; EIEN8 disabled; EIEN5 disabled; EIEN6 disabled; EIEN3 disabled; EIEN4 disabled; EIEN1 disabled; EIEN2 disabled; EIEN0 disabled; EIEN11 disabled; EIEN10 disabled; 
    ADEIEL = 0x00;
    // EIEN25 disabled; EIEN24 disabled; 
    ADEIEH = 0x00;
    // C0CIE disabled; C1CIE disabled; SHRCIE disabled; WARMTIME 32768 Source Clock Periods; 
    ADCON5H = (0xF00 & 0xF0FF); //Disabling WARMTIME bit
	
    //Assign Default Callbacks
    ADC1_SetCommonInterruptHandler(&ADC1_CallBack);
    ADC1_SetMic3InterruptHandler(&ADC1_Mic3_CallBack);
    ADC1_SetSpareAnInterruptHandler(&ADC1_SpareAn_CallBack);
    ADC1_SetMic2InterruptHandler(&ADC1_Mic2_CallBack);
    ADC1_SetMic0InterruptHandler(&ADC1_Mic0_CallBack);
    ADC1_SetMic1InterruptHandler(&ADC1_Mic1_CallBack);
    

    // Setting WARMTIME bit
    ADCON5Hbits.WARMTIME = 0xF;
    // Enabling ADC Module
    ADCON1Lbits.ADON = 0x1;
    // Enabling Power for the Shared Core
    ADC1_SharedCorePowerEnable();
    // Enabling Power for Core0
    ADC1_Core0PowerEnable();
    // Enabling Power for Core1
    ADC1_Core1PowerEnable();

    //TRGSRC0 Common Software Trigger; TRGSRC1 Common Software Trigger; 
    ADTRIG0L = 0x101;
    //TRGSRC3 Common Software Trigger; TRGSRC2 None; 
    ADTRIG0H = 0x100;
    //TRGSRC4 Common Software Trigger; TRGSRC5 None; 
    ADTRIG1L = 0x01;
    //TRGSRC6 None; TRGSRC7 None; 
    ADTRIG1H = 0x00;
    //TRGSRC8 None; TRGSRC9 Common Software Trigger; 
    ADTRIG2L = 0x100;
    //TRGSRC11 None; TRGSRC10 None; 
    ADTRIG2H = 0x00;
    //TRGSRC24 None; TRGSRC25 None; 
    ADTRIG6L = 0x00;
}

void ADC1_Core0PowerEnable ( ) 
{
    ADCON5Lbits.C0PWR = 1; 
    while(ADCON5Lbits.C0RDY == 0);
    ADCON3Hbits.C0EN = 1;     
}

void ADC1_Core1PowerEnable ( ) 
{
    ADCON5Lbits.C1PWR = 1; 
    while(ADCON5Lbits.C1RDY == 0);
    ADCON3Hbits.C1EN = 1;     
}

void ADC1_SharedCorePowerEnable ( ) 
{
    ADCON5Lbits.SHRPWR = 1;   
    while(ADCON5Lbits.SHRRDY == 0);
    ADCON3Hbits.SHREN = 1;   
}


void __attribute__ ((weak)) ADC1_CallBack ( void )
{ 

}

void ADC1_SetCommonInterruptHandler(void* handler)
{
    ADC1_CommonDefaultInterruptHandler = handler;
}

void __attribute__ ((weak)) ADC1_Tasks ( void )
{
    if(IFS5bits.ADCIF)
    {
        if(ADC1_CommonDefaultInterruptHandler) 
        { 
            ADC1_CommonDefaultInterruptHandler(); 
        }

        // clear the ADC1 interrupt flag
        IFS5bits.ADCIF = 0;
    }
}

void __attribute__ ((weak)) ADC1_Mic3_CallBack( uint16_t adcVal )
{ 

}

void ADC1_SetMic3InterruptHandler(void* handler)
{
    ADC1_Mic3DefaultInterruptHandler = handler;
}

void __attribute__ ((weak)) ADC1_Mic3_Tasks ( void )
{
    uint16_t valMic3;

    if(ADSTATLbits.AN3RDY)
    {
        //Read the ADC value from the ADCBUF
        valMic3 = ADCBUF3;

        if(ADC1_Mic3DefaultInterruptHandler) 
        { 
            ADC1_Mic3DefaultInterruptHandler(valMic3); 
        }
    }
}

void __attribute__ ((weak)) ADC1_SpareAn_CallBack( uint16_t adcVal )
{ 

}

void ADC1_SetSpareAnInterruptHandler(void* handler)
{
    ADC1_SpareAnDefaultInterruptHandler = handler;
}

void __attribute__ ((weak)) ADC1_SpareAn_Tasks ( void )
{
    uint16_t valSpareAn;

    if(ADSTATLbits.AN4RDY)
    {
        //Read the ADC value from the ADCBUF
        valSpareAn = ADCBUF4;

        if(ADC1_SpareAnDefaultInterruptHandler) 
        { 
            ADC1_SpareAnDefaultInterruptHandler(valSpareAn); 
        }
    }
}

void __attribute__ ((weak)) ADC1_Mic2_CallBack( uint16_t adcVal )
{ 

}

void ADC1_SetMic2InterruptHandler(void* handler)
{
    ADC1_Mic2DefaultInterruptHandler = handler;
}

void __attribute__ ((weak)) ADC1_Mic2_Tasks ( void )
{
    uint16_t valMic2;

    if(ADSTATLbits.AN9RDY)
    {
        //Read the ADC value from the ADCBUF
        valMic2 = ADCBUF9;

        if(ADC1_Mic2DefaultInterruptHandler) 
        { 
            ADC1_Mic2DefaultInterruptHandler(valMic2); 
        }
    }
}


void __attribute__ ((weak)) ADC1_Mic0_CallBack( uint16_t adcVal )
{ 

}

void ADC1_SetMic0InterruptHandler(void* handler)
{
    ADC1_Mic0DefaultInterruptHandler = handler;
}

void __attribute__ ((weak)) ADC1_Mic0_Tasks ( void )
{
    uint16_t valMic0;

    if(ADSTATLbits.AN0RDY)
    {
        //Read the ADC value from the ADCBUF
        valMic0 = ADCBUF0;

        if(ADC1_Mic0DefaultInterruptHandler) 
        { 
            ADC1_Mic0DefaultInterruptHandler(valMic0); 
        }
    }
}

void __attribute__ ((weak)) ADC1_Mic1_CallBack( uint16_t adcVal )
{ 

}

void ADC1_SetMic1InterruptHandler(void* handler)
{
    ADC1_Mic1DefaultInterruptHandler = handler;
}

void __attribute__ ((weak)) ADC1_Mic1_Tasks ( void )
{
    uint16_t valMic1;

    if(ADSTATLbits.AN1RDY)
    {
        //Read the ADC value from the ADCBUF
        valMic1 = ADCBUF1;

        if(ADC1_Mic1DefaultInterruptHandler) 
        { 
            ADC1_Mic1DefaultInterruptHandler(valMic1); 
        }
    }
}



/**
  End of File
*/
