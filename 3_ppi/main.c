#include "ppi.h"
#include "gpiote.h"

int main() {
    int sleep = 0;
    gpiote_init();
    init_PPI();

    while(1) {
        sleep = 10000;
        while(--sleep);
    }
    return 0;
}