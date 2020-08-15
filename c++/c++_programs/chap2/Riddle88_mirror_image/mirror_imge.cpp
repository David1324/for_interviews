#include <stdio.h>

#define M 2
#define N 3

char inputImage[M][N] ={ {1, 2, 3}, {4, 5, 6} };
char outputImage[M][N] = { 0 };

void print_table(char img[M][N])
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("0x%02X, ", img[i][j] & 0xFF);
		}
		printf("\n");
	}
}

int main()
{
	char table[256] = { 0 };
	char table1[256] = { 0 };
	for (int i = 1; i < 256; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			char temp = i >> j;
			char temp_1 = temp & 1;
			char temp_2 = 8 - j - 1;
			char temp3 = temp_1 << temp_2;
			table[i] |= temp3;
			table1[i] += temp3;
		}
		char diff = table[i] - table1[i];
		if (diff != 0)
		{
			printf("error\n");
		}
	}

	for (int m = 0; m < 8*M; m++)
	{
		for (int n = 0; n < N; n++)
		{
			int input_index = N - n - 1;
			int output_index = inputImage[m][n];
			outputImage[m][input_index] = table[output_index];
		}
	}

	printf("inputImage:\n");
	print_table(inputImage);
	printf("\n\n");
	printf("outputImage:\n");
	print_table(outputImage);
	getchar();
	return 0;
}