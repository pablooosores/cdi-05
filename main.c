#include <stdio.h>
#include "pico/stdlib.h"

int main(){
    stdio_init_all();
    gpio_init_mask(0x3ff);              // 0011 1111 1111 (GP9-GP0)
    //gpio_set_dir_in_masked(0x7 << 7);   // 0011 1000 0000 (GP9-GP7)
    gpio_set_dir_out_masked(0x7f);      // 0000 0111 1111 (GP6-GP0)
    gpio_put_masked(0x7f, 0x3f);

    int numero0=0x3f;
    int numero1=0x6;
    int numero2=0x5b;
    int numero3=0x4f;
    int numero4=0x66;
    int numero5=0x6d;
    int numero6=0x7d;
    int numero7=0x07;
    int numero8=0x7f;
    int numero9=0x6f;

    int contador=0;

    while (1){
        
        if (gpio_get(7)) {
            contador++;
            if (contador > 9) {
                contador = 9;
            }
        }
        if (gpio_get(8)) {
            contador--;
            if (contador < 0) {
                contador = 0;
            }
        }
        if (gpio_get(9)) {
            contador=0;
        }

        if (contador == 0) {
            gpio_put_masked(0x7f, numero0);
        }
        else if (contador == 1) {
            gpio_put_masked(0x7f, numero1);
        }
        else if (contador == 2) {
            gpio_put_masked(0x7f, numero2);
        }
        else if (contador == 3) {
            gpio_put_masked(0x7f, numero3);
        }
        else if (contador == 4) {
            gpio_put_masked(0x7f, numero4);
        }
        else if (contador == 5) {
            gpio_put_masked(0x7f, numero5);
        }
        else if (contador == 6) {
            gpio_put_masked(0x7f, numero6);
        }
        else if (contador == 7) {
            gpio_put_masked(0x7f, numero7);
        }
        else if (contador == 8) {
            gpio_put_masked(0x7f, numero8);
        }
        else if (contador == 9) {
            gpio_put_masked(0x7f, numero9);
        }

        sleep_ms(500);
        printf("Contador: %d\n", contador);
    }
}
