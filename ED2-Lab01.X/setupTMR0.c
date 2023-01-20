/* 
 * File:   confpuertos.h
 * Author: Pablo
 *
 * Created on 19 de enero de 2023, 05:36 PM
 */

#include "setupADC.h"
#define _XTAL_FREQ 1000000

void setupTMR0(uint8_t PRES, uint8_t valTMR0){
    INTCONbits.GIE = 1;         // Habilitar interrupciones globales
    INTCONbits.T0IE = 1;        // Habilitar interrupción de TMR0
    INTCONbits.T0IF = 0;        // Desactivar la bandera de TMR0
    
    OPTION_REGbits.T0CS = 0;    // Fosc/4
    OPTION_REGbits.PSA = 0;     // Prescaler para TMR0
    if(PRES == 2){
        OPTION_REGbits.PS = 0b000;  // Prescaler 1:2
    }
    else if(PRES == 4){
        OPTION_REGbits.PS = 0b001;  // Prescaler 1:4
    }
    else if(PRES == 8){
        OPTION_REGbits.PS = 0b010;  // Prescaler 1:8
    }
    else if(PRES == 16){
        OPTION_REGbits.PS = 0b011;  // Prescaler 1:16
    }
    else if(PRES == 32){
        OPTION_REGbits.PS = 0b100;  // Prescaler 1:32
    }
    else if(PRES == 64){
        OPTION_REGbits.PS = 0b101;  // Prescaler 1:64
    }
    else if(PRES == 128){
        OPTION_REGbits.PS = 0b110;  // Prescaler 1:128
    }
    else if(PRES == 256){
        OPTION_REGbits.PS = 0b111;  // Prescaler 1:256
    }
    
    TMR0 = valTMR0;                   // Valor inicial del TMR0
}
