#include "uart.h"
#include "gpio.h"
#include <stdio.h>


ssize_t _write(int fd, const void *buf, size_t count){
    char * letter = (char *)(buf);
    for(int i = 0; i < count; i++){
        uart_send(*letter);
        letter++;
    }
    return count;
}

int main(){

	int sleep = 0;
    //char read_value;
	gpio_init();
	uart_init();

	while(1){
        if (!(GPIO0->IN & (1 << 23))) { //button B
			//gpio_lights_on();	
			uart_send('B');
		}
		if (!(GPIO0->IN & (1 << 14))) { //button A
			//gpio_lights_off();
			uart_send('A');
		}
		if (uart_read() != '\0') {
			gpio_lights_on();
		}
		
		sleep = 10000;
		while(--sleep);
		//iprintf("The average grade in TTK%d was in %d and %d: %c\n\r",4235,2019,2018,'C');
	}
	return 0;
}