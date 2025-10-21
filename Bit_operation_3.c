#include <stdio.h>

int main(void) {
    unsigned int num;
    int count = 0;
    
    printf("Введите целое положительное число: ");
    if (scanf("%u", &num) != 1) {
        printf("Ошибка ввода!\n");
        return 1;
    }
    
    // Подсчет единиц с помощью битовых операций
    while (num) {
        if (num & 1) {  // Проверяем младший бит
            count++;
        }
        num >>= 1;      // Сдвигаем число вправо
    }
    
    printf("Количество единиц в двоичном представлении: %d\n", count);
    return 0;
}
