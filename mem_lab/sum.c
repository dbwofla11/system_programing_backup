#include<stdio.h>
#include<stdlib.h>

#define COLS 10000
#define ROWS 10000

int sum_array_rows(int** a)
{
	return 0;
}

int sum_array_cols(int** a)
{
	return 0;
}

int main()
{
    int** a;
    int i, j;

    a = (int**)malloc(sizeof(int*) * ROWS);

    for(i = 0; i < ROWS; i++)
        a[i] = (int*)malloc(sizeof(int)*COLS);


    for(i = 0; i < ROWS; i++)
        for(j = 0; j < COLS; j++)
            a[i][j] = i;

#ifdef SUM_COLS     
    int sum = sum_array_cols(a);
    printf("sum_cols ... \n");
#endif

#ifdef SUM_ROWS
    printf("sum_rows ... \n");
    int sum = sum_array_rows(a);
#endif

    printf("sum = %d\n", sum);

    return 0;
}


