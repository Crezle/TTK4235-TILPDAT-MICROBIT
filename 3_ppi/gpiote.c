#include "gpiote.h"
#include "gpio.h"

void gpiote_init() {
    GPIO0->PIN_CNF[28] = 1; //Col 1
    GPIO0->PIN_CNF[11] = 1; //Col 2
    GPIO0->PIN_CNF[31] = 1; //Col 3
    GPIO1->PIN_CNF[5] = 1;  //Col 4
    GPIO0->PIN_CNF[30] = 1; //Col 5 

    GPIOTE->CONFIG[0] = (1 << 0) | (14 << 8) | (0 << 13) | (2 << 16);

    GPIOTE->CONFIG[1] = (3 << 0) | (21 << 8) | (0 << 13) | (3 << 16) | (0 << 20);
    GPIOTE->CONFIG[2] = (3 << 0) | (22 << 8) | (0 << 13) | (3 << 16) | (0 << 20);
    GPIOTE->CONFIG[3] = (3 << 0) | (15 << 8) | (0 << 13) | (3 << 16) | (0 << 20);
    GPIOTE->CONFIG[4] = (3 << 0) | (24 << 8) | (0 << 13) | (3 << 16) | (0 << 20);
    GPIOTE->CONFIG[5] = (3 << 0) | (19 << 8) | (0 << 13) | (3 << 16) | (0 << 20);

} 