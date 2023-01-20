/* 
 * File:   confpuertos.h
 * Author: Pablo
 *
 * Created on 19 de enero de 2023, 05:36 PM
 */

#include "display.h"

int d1;
int d2;

int display(int lecADC, int disp){
    if (disp == 1){
        d1 = convdisp((lecADC & 0x0F));
        return d1;
    }
    else if (disp == 2){
        d2 = convdisp((lecADC & 0xF0) >> 4);
        return d2;
    }
}

int convdisp(int valor){
    if (valor == 0){
        return 0b00111111;
    }
    else if(valor == 1){
        return 0b00000110;
    }
    else if(valor == 2){
        return 0b01011011;
    }
    else if(valor == 3){
        return 0b01001111;
    }
    else if(valor == 4){
        return 0b01100110;
    }
    else if(valor == 5){
        return 0b01101101;
    }
    else if(valor == 6){
        return 0b01111101;
    }
    else if(valor == 7){
        return 0b00000111;
    }
    else if(valor == 8){
        return 0b01111111;
    }
    else if(valor == 9){
        return 0b01101111;
    }
    else if(valor == 10){
        return 0b01110111;
    }
    else if(valor == 11){
        return 0b01111100;
    }
    else if(valor == 12){
        return 0b00111001;
    }
    else if(valor == 13){
        return 0b01011110;
    }
    else if(valor == 14){
        return 0b01111001;
    }
    else if(valor == 15){
        return 0b01110001;
    }
}