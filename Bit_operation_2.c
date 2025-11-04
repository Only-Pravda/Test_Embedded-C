#include <stdio.h> 

int main(void) {
    int n;
    printf("Введите целое отрицательное число: ");
    if (scanf("%d", &n) != 1 || n >= 0) {
        printf("Ошибка ввода! Введите отрицательное число.\n");
        return 1;
    }

    int bits = sizeof(n) * 8;
    printf("Двоичное представление: ");
    for (int i = bits - 1; i >= 0; i--) {
        int mask = 1 << i;
        putchar((n & mask) ? '1' : '0');
    }
    putchar('\n');
    return 0;
}









