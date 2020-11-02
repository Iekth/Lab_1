// Lab_5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include<stdio.h>
#include<conio.h>



int main() {
	int sum = 0;



	int arr[2][3] = { 5,5,5,
					  5,5,5 };

	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 3; j++)




		{
		

	if (arr[i][j] % 2 != 0 && i % 2 == 0 && j % 2 == 0)
		sum = arr[i][j] + sum;

}
			


		printf("%d\n", sum);
	}
