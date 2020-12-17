#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <locale.h>

#define False 0
#define True 1

void inoutstring(char[], int);				// прототип функции ввода-вывода
int  identremove(char[], char[], int n);		// прототип функции удаления совпадающих элементов
int main()
{
	setlocale(0, "Russian");
	srand(time(NULL));

	char* string1, * string2;
	int n;

	rewind(stdin);

	printf_s("Введите размер строки: \n");
	scanf_s("%d", &n);

	if (!(string1 = (char*)calloc(n, sizeof(char))) || !(string2 = (char*)calloc(n, sizeof(char))))			// выделяем память с проверкой
	{
		printf_s("Недостаточно памяти.Перезапустить программу!\n");
		return 0;
	}

	printf_s("Первая строка: ");

	inoutstring(string1, n);

	printf_s("Вторая строка: ");

	inoutstring(string2, n);

	identremove(string1, string2, n);

	putchar('\n');

	system("pause");

	return 0;
}

void inoutstring(char string[], int n)
{
	for (int i = 0; i < n; i++)									// вводим 
		string[i] = ('a' + rand() % ('z' - 'a'));

	for (int i = 0; i < n; i++)									// выводим :)
		printf_s("%c", string[i]);

	putchar('\n');

}

int identremove(char s1[], char s2[], int n)
{
	int i, j, k, flag = False;

	// Пока не конец строки и размер строки не максимален
	//если символ строки не равен символу второй строки т.е. элементу для удаления
	//записываем символ по j, после этого увеличиваем на единицу

	for (k = 0; s2[k] != '\0' && k < n; k++) {
		for (i = j = 0; s1[i] != '\0' && i < n && j < n; i++)
		{
			if (s1[i] != s2[k])
			{
				s1[j++] = s1[i];
				flag = True;
			}
		}
		s1[j] = '\0';
	}

	if (flag == False)
	{
		printf_s("Ничего не изменилось\n");
		return False;
	}

	printf_s("\nОтредактированная строка: ");
	for (k = 0; k < n; k++)
		printf_s("%c", s1[k]);

	return False;
}