#include <stdio.h>
#include <conio.h>
#include <iostream>

int main()
{
	setlocale(0, "Russian");

	int year, p1, p2, p3, p4, p5, date;
	printf("Введ0ите год: ");
	scanf_s("%d", &year);
	printf("%d", year);
	p1 = year / 400 - 1994 / 400;
	p2 = year / 100 - 1994 / 100;
	p3 = year / 4 - 1994 / 4;
	date = (year - 1994) * 365 + p3 - p2 + p1;
	p4 = date % 7;

	if (p4 >= 2)
		p5 = 9 - p4;
	else
		p5 = 2 - p4;


	printf(" День учителя в %dг. будет %d октября.", year, p5);
	return 0;
}