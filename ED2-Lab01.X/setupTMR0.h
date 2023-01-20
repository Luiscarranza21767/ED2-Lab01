/* 
 * File:   setupTMR0.h
 * Author: Pablo
 *
 * Created on 19 de enero de 2023, 06:32 PM
 */

#ifndef SETUPTMR0_H
#define	SETUPTMR0_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

void setupTMR0(uint8_t PRES, uint8_t valTMR0);

#endif	/* SETUPTMR0_H */

