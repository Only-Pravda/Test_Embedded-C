#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

int main(void) {
    printf("Hello, world!\n");
    unsigned int n;
    printf("Введите целое положительное число: ");
    fflush(stdout);

    char buf[64];
    if (!fgets(buf, sizeof(buf), stdin)) {
        printf("Ошибка ввода!\n");
        return 1;
    }
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') buf[len - 1] = '\0';

    // Проверка на минус в любой позиции
    for (size_t i = 0; i < len; ++i) {
        if (buf[i] == '-') {
            printf("Ошибка: отрицательные числа запрещены!\n");
            return 1;
        }
    }

    char *endptr = NULL;
    unsigned long tmp = strtoul(buf, &endptr, 10);
    if (endptr == buf || *endptr != '\0') {
        printf("Ошибка: введите только целое положительное число без точек, запятых и других символов!\n");
        return 1;
    }
    if (tmp == 0 || tmp > UINT_MAX) {
        printf("Ошибка: введите положительное число в диапазоне 1..%u!\n", UINT_MAX);
        return 1;
    }
    n = (unsigned int)tmp;
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





