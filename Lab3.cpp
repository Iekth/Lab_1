#include <stdio.h>
#include <conio.h>
#include <iostream>

int main()
{
	setlocale(0, "Russian");

	int year, g1, g2, g3, g4, g5, date;

	printf("Введите год: ");

	scanf_s("%d", &year);

	if (year < 0) {
		year *= -1;
	}
	
	
		g1 = year / 400 - 1994 / 400;
	g2 = year / 100 - 1994 / 100;
	g3 = year / 4 - 1994 / 4;
	date = (year - 1994) * 365 + g3 - g2 + g1;
g4 = date % 7;

	if (g4 >= 2)
		g5 = 9 - g4;
	else
		g5 = 2 - g4;


	printf(" День учителя в %dг. будет %d октября.", year, g5);
	return 0;
}