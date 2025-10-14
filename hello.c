#include <stdio.h> 

int main(void) {
    printf("Hello, world!\n");
    unsigned int n;
    printf("Введите целое положительное число: ");
    if (scanf("%u", &n) != 1) {
        printf("Ошибка ввода!\n");
        return 1;
    }

    int bits = sizeof(n) * 8;
    int started = 0;
    printf("Двоичное представление: ");
    for (int i = bits - 1; i >= 0; i--) {
        unsigned int mask = 1u << i;
        if (n & mask) {
            started = 1;
            putchar('1');
        } else if (started) {
            putchar('0');
        }
    }
    if (!started) putchar('0');
    putchar('\n');
    return 0;
}





