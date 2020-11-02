#include <stdio.h>
#include <locale.h>
#include <windows.h>
#define SIZE 9


int main() {

	int arr[SIZE] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 }; //числа из примера, должны получить 9, 0, 9, 9, 0, 4, 5, 0, 0
	int i, j, g;

	setlocale(LC_ALL, "Russian"); //русификация

	//ввод чисел вручную
	
	for (i = 0; i < SIZE; i++) {
		printf("введите элемент, пожалуйста  ");
		scanf_s("%d", &arr[i]);
	}
	system("CLS"); 

	//вывод введенных чисел
	printf("изначальные числа:");
	for (i = 0; i < SIZE; i++) {
		printf("%2d", arr[i]);
	}

	for (i = 0; i < SIZE; i++) {
		g = arr[i]; 
		j = i + 1; 

		if (arr[i] < arr[j]) { 
			arr[i] = arr[j];

		}
		else {
			j++; //рассматриваем следующее число
			for (j; j < SIZE; j++) {
				if (arr[i] < arr[j]) {
					arr[i] = arr[j];
				}
			}
		}

		if (arr[i] == g) 
			arr[i] = 0;
	}

	printf("\n   конечные числа:"); //вывод результата
	for (i = 0; i < SIZE; i++) {
		printf("%2d", arr[i]);
	}
}
