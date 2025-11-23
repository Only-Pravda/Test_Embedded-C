#include <stdio.h> 

int main(void) {
    int n;
    printf("Введите целое отрицательное число: ");
    if (scanf("%d", &n) != 1 || n >= 0) {
        printf("Ошибка ввода! Введите отрицательное число.\n");
        return 1;
    }

    int bits = sizeof(n) * 8;

    // Безопасно работаем с битами через беззнаковый тип
    unsigned int un = (unsigned int)n;
    printf("Двоичное представление (двойное дополнение): ");
    for (int i = bits - 1; i >= 0; i--) {
        putchar(((un >> i) & 1u) ? '1' : '0');
    }
    putchar('\n');

    // Дополнительно выведем модуль числа (без знака) — чтобы было видно, какие биты 'величины' числа
    unsigned int mag = (unsigned int)(-(long long)n);
    // Выводим модуль без ведущих нулей
    printf("Модуль числа в двоичном (без ведущих нулей): ");
    int started = 0;
    for (int i = bits - 1; i >= 0; i--) {
        if ((mag >> i) & 1u) {
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









