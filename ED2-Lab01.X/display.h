/* 
 * File:   display.h
 * Author: Pablo
 *
 * Created on 19 de enero de 2023, 10:25 PM
 */

#ifndef DISPLAY_H
#define	DISPLAY_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

int display(int lecADC, int disp);
int convdisp(int valor);

#endif	/* DISPLAY_H */

