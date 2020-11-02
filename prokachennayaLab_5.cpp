#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <clocale>



int main(void) {
	setlocale(LC_ALL, "Russian");

	int j, i, num[2][3], sum = 0;
	/* загрузка чисел */
	for (i = 0; i < 2; ++i)
		for (j = 0; j < 3; ++j)
			num[i][j] = (i * 3) + j + 1;

	/* вывод чисел */
	
	for (i = 0; i < 2; ++i)
	{
		for (j = 0; j < 3; ++j)
			printf("%3d", num[i][j]);
		printf("\n");
	}
	{   for (i = 0; i < 2; ++i)
		for (j = 0; j < 3; ++j)

			if (num[i][j] % 2 != 0 && i % 2 == 0 && j % 2 == 0)
				sum += num[i][j];
	printf("Сумма  равна: ");
	printf("%d\n", sum);
	}
	
	

}
