#include <stdio.h>

int main(void) {
    unsigned int num;
    unsigned char new_byte;
    
    printf("Введите целое положительное число: ");
    fflush(stdout);
    
    char after_num;
    if (scanf("%u%c", &num, &after_num) != 2 || after_num != '\n') {
        printf("Ошибка: введите целое положительное число без десятичных точек!\n");
        return 1;
    }
    
    printf("Введите новое значение для третьего байта (0-255): ");
    fflush(stdout);
    
    if (scanf("%hhu%c", &new_byte, &after_num) != 2 || after_num != '\n') {
        printf("Ошибка: введите целое число от 0 до 255 без десятичных точек!\n");
        return 1;
    }

        // Выводим двоичное представление нового байта
        printf("Двоичное представление нового байта: ");
        for (int i = 7; i >= 0; i--) {
            putchar((new_byte & (1u << i)) ? '1' : '0');
        }
        putchar('\n');
    
    // Вывод исходного числа в двоичном виде
    printf("\nИсходное число в двоичном виде:\n");
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


