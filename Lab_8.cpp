#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void osn(char*, int);
int main() {
setlocale(LC_ALL, "RUS");
char ****str;
int n1, n, m, dl, i, j,k,i1,i2;
printf_s("Введите кол-во матриц:\nn1 = ");
scanf_s("%d", &n1);
printf_s("Введите кол-во строк матриц:\nn = ");
scanf_s("%d", &n);
printf_s("Введите кол-во столбцов матриц:\nm = ");
scanf_s("%d", &m);
printf_s("Введите кол-во символов в строках, строки - каждый элемент матрицы:\ndl = ");
scanf_s("%d", &dl);
str = (char****)malloc(sizeof(char**) * n1);
for (i = 0; i < n1; i++)
*(str + i) = (char***)malloc(sizeof(char) * n);
for (i = 0; i < n1; i++)
for (j = 0; j < n; j++)
*(*(str + i) + j) = (char**)malloc(sizeof(char) * m);
for (i = 0; i < n1; i++)
for (j = 0; j < n; j++)
for (k = 0; k < m; k++)
*(*(*(str + i) + j) + k) = (char*)malloc(sizeof(char) * dl);
if (str == nullptr) printf_s("No memory");
printf_s("Вводите вашу строку:\n");
rewind(stdin);
for (i = 0; i < n1; i++)
for (j = 0; j < n; j++)
for (k = 0; k < m; k++)
fgets(*(*(*(str + i) + j) + k), dl, stdin);
for (i = 0; i < n1; i++)
for (j = 0; j < n; j++)
for (k = 0; k < m; k++)
for (int a = 0; a < dl; a++)
if (*(*(*(*(str + i) + j) + k) + a) == '\n') *(*(*(*(str + i) + j) + k) + a) = '\0';
printf_s("\nСлова, которые читаются справа и слева одинаково:\n");
for (i = 0; i < n1 && *(*(*(*(str + i)))) != '\0'; i++)
for (j = 0; j < n && *(*(*(*(str + i) + j))) != '\0'; j++)
for (k = 0; k < m && *(*(*(*(str + i) + j) + k)) != '\0'; k++)
for (int a = 0; a < dl && *(*(*(*(str + i) + j) + k) + a) != '\0';) {
if (*(*(*(*(str + i) + j) + k) + a) == ' ') while (*(*(*(*(str + i) + j) + k) + a) == ' ' && *(*(*(*(str + i) + j) + k) + a) != '\0') a++;
i1 = a;
for (i2 = 0; *(*(*(*(str + i) + j) + k) + a) != ' ' && *(*(*(*(str + i) + j) + k) + a) != '\0'; i2++, a++);

char* str2;
str2 = (char*) malloc(sizeof(char) * (i2 + 1));
for (int b = 0; b < i2 + 1; b++, i1++) {
*(str2 + b) = *(*(*(*(str + i) + j) + k) + i1);
if (b == i2) *(str2 + b) = '\0';
}
osn(str2, i2);
free(str2);
}


free(str);
}

void osn(char* str2, int raz) {
int i,k = 0, j;
j=raz-1;
for (i = 0; i <= j; i++) {
if (*(str2 + i) == *(str2 + j)) k++;
else {
k = 0;
break;
}
j--;
}
if (k != 0) {
for (i = 0; i < raz; i++)
printf_s("%c", *(str2 + i));
printf_s(" ");
}
}
