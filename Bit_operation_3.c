#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    unsigned int num;
    int count = 0;

    printf("Введите целое положительное число: ");
    fflush(stdout);
    char buf[64];
    if (!fgets(buf, sizeof(buf), stdin)) {
        printf("Ошибка ввода!\n");
        return 1;
    }
    size_t len = strlen(buf);
    if (len > 0 && buf[len - 1] == '\n') buf[len - 1] = '\0';

    // Проверяем наличие минуса в любом месте строки
    for (size_t i = 0; i < len; ++i) {
        if (buf[i] == '-') {
            printf("Ошибка: отрицательные числа запрещены!\n");
            return 1;
        }
    }
    char *endptr = NULL;
    num = strtoul(buf, &endptr, 10);
    if (endptr == buf || *endptr != '\0') {
        printf("Ошибка: введите только целое положительное число без точек, запятых и других символов!\n");
        return 1;
    }
    
    if (num < 0) {
        printf("Ошибка: введите положительное число (без знака '-')!\n");
        return 1;
    }

    // Подсчет единиц с помощью битовых операций
    while (num) {
        if (num & 1) {
            count++;
        }
        num >>= 1;
    }

    printf("Количество единиц в двоичном представлении: %d\n", count);
    return 0;
}
