#include "uart.h"
#include "gpio.h"

void uart_init() {
    GPIO0->PIN_CNF[6] = 0; //RX
    GPIO1->PIN_CNF[8] = 1; //TX

    //UART0->PSEL_RXD &= ~0x1F;
    //UART0->PSEL_RXD |= (6);
    // UART0->PSEL_RXD &= ~(1<<5);
    // UART0->PSEL_RXD &= ~(1<<31);
    UART0->PSEL_TXD = 6 | (0<<5) | (0<<31);

    //UART0->PSEL_TXD &= ~0x1F;
    // UART0->PSEL_TXD |= (8);
    // UART0->PSEL_TXD |= (1<<5);
    // UART0->PSEL_TXD &= ~(1<<31);
    UART0->PSEL_RXD = 8 | (1<<5) | (0<<31);

    UART0->BAUDRATE = 9600;

    UART0->PSEL_RTS = (1<<31);

    UART0->PSEL_CTS = (1<<31);

    UART0->ENABLE = 4;
    
    UART0->TASKS_STARTRX = 1;
}

// void uart_init(void){
//     GPIO0->PIN_CNF[6] = 0;  // RX, input
//     GPIO1->PIN_CNF[8] = 1;  // TX, output
//     UART0->PSEL_RXD = 8 | (1 << 5);
//     UART0->PSEL_TXD = 6;
//     UART0->BAUDRATE = 0x00275000;
//     UART0->PSEL_RTS = 1 << 31;
//     UART0->PSEL_CTS = 1 << 31;
//     UART0->ENABLE = 4;
//     UART0->TASKS_STARTRX = 1;

//     return;
// }

void uart_send(char letter) {
    UART0->TASKS_STARTTX = 1;

    UART0->TXD = letter;
    while(!(UART0->EVENTS_TXDRDY)) {}
    UART0->EVENTS_TXDRDY = 0;
    UART0->TASKS_STOPTX = 1;
}

char uart_read() {
    if(UART0->EVENTS_RXDRDY){
        char letter = UART0->RXD;
        UART0->EVENTS_RXDRDY = 0;
        return letter;
    }
    return '\0';


    // char letter = '\0';
    // UART0->EVENTS_RXDRDY = 0;
    // if ((char) UART0->RXD != letter) {
    //     letter = (char) UART0->RXD;
    // }
    // return letter;
}