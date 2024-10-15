#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void strasen_matrix(int a[2][2], int b[2][2], int result[2][2])
{
	int P = (a[0][0] + a[1][1]) * (b[0][0] + b[1][1]);
	int Q = (a[1][0] + a[1][1]) * b[0][0];
	int R = a[0][0] * (b[0][1] - b[1][1]);
	int S = a[1][1] * (b[1][0] - b[0][0]);
	int T = (a[0][0] + a[0][1]) * b[1][1];
	int U = (a[1][0] - a[0][0]) * (b[0][0] + b[0][1]);
	int V = (a[0][1] - a[1][1]) * (b[1][0] + b[1][1]);
	result[0][0] = P + S - T + V;
	result[0][1] = R + T;
	result[1][0] = Q + S;
	result[1][1] = P - Q + R + U;
}
void naive_matrix(int a[2][2], int b[2][2], int result[2][2])
{
	result[0][0] = (a[0][0] * b[0][0]) + (a[0][1] * b[1][0]);
	result[0][1] = (a[0][0] * b[0][1]) + (a[0][1] * b[1][1]);
	result[1][0] = (a[1][0] * b[0][0]) + (a[1][1] * b[1][0]);
	result[1][1] = (a[1][0] * b[0][1]) + (a[1][1] * b[1][1]);
}
int main()
{
	int a[2][2], b[2][2], result1[2][2], result2[2][2], i, j;
	printf("Enter the 4 elements of the first matrix:\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (scanf("%d", &a[i][j]) != 1)
			{
				fprintf(stderr, "Error: Invalid input for matrix A.\n");
				return 1;
			}
		}
	}
	printf("Enter the 4 elements of the second matrix:\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			if (scanf("%d", &b[i][j]) != 1)
			{
				fprintf(stderr, "Error: Invalid input for matrix B.\n");
				return 1;
			}
		}
	}

	// Calculate results using Strassen's algorithm
	clock_t start_strassen = clock();
	strasen_matrix(a, b, result1);
	clock_t end_strassen = clock();

	// Calculate results using the naive algorithm
	clock_t start_naive = clock();
	naive_matrix(a, b, result2);
	clock_t end_naive = clock();

	// Print results and execution times
	printf("Strassen's matrix result:\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%d ", result1[i][j]);
		}
		printf("\n");
	}
	printf("Execution time for Strassen's algorithm: %.10f seconds\n", (double)(end_strassen - start_strassen) / CLOCKS_PER_SEC);

	printf("\nNaive matrix result:\n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 2; j++)
		{
			printf("%d ", result2[i][j]);
		}
		printf("\n");
	}
	printf("Execution time for the naive algorithm: %.10f seconds\n", (double)(end_naive - start_naive) / CLOCKS_PER_SEC);

	return 0;
}