/* Universidad del Valle de Guatemala
 IE3054 Electrónica Digital 2
 Autor: Luis Pablo Carranza
 Compilador: XC8, MPLAB X IDE (v6.00)
 Proyecto: Laboratorio No.01
 Hardware PIC16F887
 Creado: 19/01/23
 Última Modificación: 19/01/23*/

// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT // Oscillator Selection bits (INTOSC 
//oscillator without clock out)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and 
//can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR 
//pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code 
//protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code 
//protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/
//External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-
//Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin 
//has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit 
//(Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits 
//(Write protection off)

#include <xc.h> // include processor files - each processor file is guarded.  

#include "oscilador.h"
#include "confpuertos.h"
#include "setupADC.h"
#include "setupTMR0.h"
#include "display.h"

#define _XTAL_FREQ 4000000
#define vTMR0 10

int cont;
int lecADC;


void __interrupt() isr (void){
    if(INTCONbits.RBIF){
        if(PORTBbits.RB7 == 0){
            cont = 1;
        }
        if(PORTBbits.RB6 == 0){
            cont = 2;
        }
        INTCONbits.RBIF = 0;
    }
    if(PIR1bits.ADIF){
        lecADC = ADRESH;
        ADIF = 0;                   // Apaga la bandera del ADC
    }
    if(INTCONbits.T0IF){
        
        if(PORTEbits.RE0){
            PORTD = display(lecADC, 2);
            PORTEbits.RE0 = 0;
            PORTEbits.RE1 = 1;
        }
        else {
            PORTD = display(lecADC, 1);
            PORTEbits.RE0 = 1;
            PORTEbits.RE1 = 0;
        }
        
        TMR0 = vTMR0;               // Carga el valor del timer
        INTCONbits.T0IF = 0;
        
    }
}

void main(void) {
    configpuertos();
    setupINTOSC(6);     // Oscilador a 4 MHz
    setup_ADC();
    setupTMR0(64, vTMR0);
    cont = 0;
    
    PORTEbits.RE0 = 1;
    PORTEbits.RE1 = 0;
    
    ANSELbits.ANS5 = 0;
    ANSELbits.ANS6 = 0;
    
    while(1){
        // Contador (PRELAB)
        if((cont == 1) & PORTBbits.RB7){ // Revisa que ya se haya soltado el 
            PORTC ++;                    // botón como antirrebote
            cont = 0;
        }
        if((cont == 2) & PORTBbits.RB6){
            PORTC --;
            cont = 0;
        }
        
        //ADC (LAB)
        iniciarADC(1);
        
        
        if(lecADC > PORTC){
            PORTBbits.RB0 = 1;
        }
        else { 
            PORTBbits.RB0 = 0;
        }
    }
}

