#include <stdio.h>
#include <locale.h>

int main(void) {
    setlocale(LC_ALL, ".UTF8");
    
    unsigned int num;
    unsigned char new_byte;
    
    printf("Введите целое положительное число: ");
    fflush(stdout);
    if (scanf("%u", &num) != 1) {
        printf("Ошибка ввода числа!\n");
        return 1;
    }
    
    printf("Введите новое значение для третьего байта (0-255): ");
    fflush(stdout);
    if (scanf("%hhu", &new_byte) != 1) {
        printf("Ошибка ввода байта!\n");
        return 1;
    }
    
    // Вывод исходного числа в двоичном виде
    printf("\n Исходное число в двоичном виде:\n");
    for (int i = 31; i >= 0; i--) {
        putchar((num & (1u << i)) ? '1' : '0');
        if (i % 8 == 0) putchar(' '); // Разделяем байты пробелами
    }
    printf("\n");
    
    // Замена третьего байта
    // Сначала очищаем третий байт (биты 16-23)
    num &= ~(0xFF << 16);
    // Затем устанавливаем новое значение
    num |= ((unsigned int)new_byte << 16);
    
    // Вывод результата в двоичном виде
    printf("Число после замены третьего байта:\n");
    for (int i = 31; i >= 0; i--) {
        putchar((num & (1u << i)) ? '1' : '0');
        if (i % 8 == 0) putchar(' '); // Разделяем байты пробелами
    }
    printf("\n");
    
    printf("Результат в десятичном виде: %u\n", num);
    return 0;
}


