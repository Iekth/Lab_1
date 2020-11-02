
#include <stdio.h>
#include <clocale>



int main(void) {
	setlocale(LC_ALL, "Russian");

	int j, i, num[2][3], sum = 0;
	/* çàãðóçêà ÷èñåë */
	for (i = 0; i < 2; ++i)
		for (j = 0; j < 3; ++j)
			num[i][j] = (i * 3) + j + 1;

	/* âûâîä ÷èñåë */
	
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
	printf("Ñóììà  ðàâíà: ");
	printf("%d\n", sum);
	}
	
	

}
