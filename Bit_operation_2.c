#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	int n;
	printf("Введите целое отрицательное число: ");
	fflush(stdout);

	char buf[64];
	if (!fgets(buf, sizeof(buf), stdin)) {
		printf("Ошибка ввода!\n");
		return 1;
	}
	size_t len = strlen(buf);
	if (len > 0 && buf[len - 1] == '\n') buf[len - 1] = '\0';

	char *endptr = NULL;
	long tmp = strtol(buf, &endptr, 10);
	if (endptr == buf || *endptr != '\0') {
		printf("Ошибка: вводите только целое отрицательное число!\n");
		return 1;
	}
	if (tmp >= 0) {
		printf("Ошибка: число должно быть отрицательным!\n");
		return 1;
	}
	n = (int)tmp;

	int bits = sizeof(n) * 8;
	unsigned int un = (unsigned int)n;
	printf("Двоичное представление: ");
	for (int i = bits - 1; i >= 0; i--) {
		putchar(((un >> i) & 1u) ? '1' : '0');
	}
	putchar('\n');
	return 0;
}


