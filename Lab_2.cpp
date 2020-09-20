#include <stdio.h>

int main()
{
    int A[10] = { -1, 2, 4, 7, -7, -9, 10, 20, -100, -4
    };
    int sum_1 = 0, sum_2 = 0, i = 0;
    for (i = 0; i < 10; i++) {
        if (A[i] > 0)
            sum_1 += A[i];
        else
            sum_2 += A[i];

    }
    printf("%d  %d", sum_1,     sum_2);

    return 0;
}