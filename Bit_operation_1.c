#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main(void) {
    printf("Hello, world!\n");
    unsigned int n;
    printf("Введите целое положительное число: ");
    fflush(stdout);

    char buf[64];
    if (!fgets(buf, sizeof(buf), stdin)) {
        printf("Ошибка ввода!\n");
        return 1;ы
    }
    // Удалим перевод строки в конце, если есть
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') buf[len - 1] = '\0';

    // Парсим как long, чтобы проверить знак и переполнение
    char *endptr = NULL;
    long tmp = strtol(buf, &endptr, 10);
    if (endptr == buf || *endptr != '\0') {
        printf("Ошибка: введите целое положительное число без десятичных точек!\n");
        return 1;
    }
    if (tmp < 0) {
        printf("Ошибка: введите положительное число (без знака '-')!\n");
        return 1;
    }
    if ((unsigned long)tmp > UINT_MAX) {
        printf("Ошибка: число слишком большое!\n");
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





