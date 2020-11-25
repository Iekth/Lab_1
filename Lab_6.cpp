#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int main()
{
	int** a; // указатель на массив
	int i, j, n, m, max = 0, min = 0, max_i = 0, max_j = 0, min_i = 0, min_j = 0;
	system("chcp 1251");
	system("cls");
	printf("Введите количество строк: ");

	scanf_s("%d", &n);
	printf("Введите количество столбцов: ");
	scanf_s("%d", &m);
	// Выделение памяти
	a = (int**)malloc(n * sizeof(int*));
	for (i = 0; i < n; i++) // цикл по строкам
	{
		*(a + i) = (int*)malloc(m * sizeof(int*));
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf_s("%d", *(a + i) + j);
		}

	// Вывод элементов массива
	for (i = 0; i < n; i++) // цикл по строкам
	{
		for (j = 0; j < m; j++) // цикл по столбцам
		{
			printf("%4d ", *(*(a + i) + j));
		}
		printf("\n");
	}
	printf("\n\n");
	int counter = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (*(*(a + i) + j) < 0)
			{
				max = *(*(a + i) + j);
				max_i = i;
				max_j = j;
				counter = 1;
				break;
			}
		}
		if (counter) break;
	}
	counter = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (*(*(a + i) + j) > 0)
			{
				min = *(*(a + i) + j);
				min_i = i;
				min_j = j;
				counter = 1;
				break;
			}
		}
		if (counter) break;
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{

			if (max < a[i][j] && a[i][j] < 0)
			{
				max = a[i][j];
				max_i = i;
				max_j = j;

			}
			if (min > a[i][j] && a[i][j] > 0)
			{
				min = a[i][j];
				min_i = i;
				min_j = j;
			}
		}
	}


	int tmp = a[min_i][min_j];
	a[min_i][min_j] = a[max_i][max_j];
	a[max_i][max_j] = tmp;


	for (i = 0; i < n; i++) // цикл по строкам
	{
		for (j = 0; j < m; j++) // цикл по столбцам
		{
			printf("%4d ", *(*(a + i) + j));
		}
		printf("\n");
	}

	free(a);

}