#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <locale.h>
int input_check(int* col);
int choice_input_check();
void arr_input_check(int arr[100][100], int col);
void arr_rand_input(int arr[100][100], int col);
void output_arr(int arr[100][100], int col);
int sum(int arr[100][100], int col);
int minn(int arr[100][100], int col);
int main()
{
	int	arr[100][100], col, choice = 0;
	input_check(&col);
	choice = choice_input_check();
	switch (choice)
	{
	case 1:
		arr_input_check(arr, col);
		break;
	case 2:
		arr_rand_input(arr, col);
		break;
	default:
		return 0;
		break;
	}
	output_arr(arr, col);
	printf(sum(arr, col), minn(arr, col));
}
int input_check(int* col)
{

	printf("Enter arr size\n");
	while (scanf_s("%d", col) == 0 || *col >= 101 || *col < 1)
	{
		printf("Wrong input.\n");
		rewind(stdin);
	}
}
int choice_input_check()
{
	int input;
	printf("Print 1 for manually 2 random\n");
	while (scanf_s("%d", &input) < 1 || input > 2)
	{
		printf_s("Wrong input\n");
		rewind(stdin);
	}
	return input;
}
void arr_input_check(int arr[100][100], int col)
{
	for (int i = 0; i < col; i++)
	{
		printf("Enter the elements of the %d row\n", i + 1);
		for (int j = 0; j < col; j++)
		{
			while (scanf_s("%d", &arr[i][j]) == 0)
			{
				printf("Wrong input.\n");
				rewind(stdin);
			}
		}
	}
}
void arr_rand_input(int arr[100][100], int col)
{
	srand(time(NULL));
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 200 - 100;
		}

	}
}
void output_arr(int arr[100][100], int col)
{
	for (int i = 0; i < col; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d \t", arr[i][j]);
		}
		printf("\n");
	}
}
int sum(int arr[100][100], int col)
{
	for (int j = 0; j < col; j++)
	{
		int a = 0;
		int sum = 0;
		for (int i = 0; i < col; i++)
		{
			if (arr[i][j] > -1)
			{
				a++;
			}
		}
		if (a == col)
		{
			for (int k = 0; k < col; k++)
			{
				sum += arr[k][j];
			}
		}
		if (sum > 0)
		{
			printf("\nSumma stolbca %d  = %d", j + 1, sum);
		}
		else
		{
			printf("\nCol %d has a negative element", j + 1);
		}
	}
}
int minn(int arr[100][100], int col)
{
	int sum1 = 0, sum2 = 0;
	for (int i = 0, j = col - 2; j >= 0, i < col - 1; j = j - 1, i++)
	{
		sum1 += abs(arr[i][j]);
	}
	for (int i = 1, j = col - 1; j > 0, i < col; j--, i++)
	{
		sum2 += abs(arr[i][j]);
	}
	if (sum1 < sum2)
	{
		printf("Min sum %d", sum1);
	}
	else
	{
		printf("Min sum %d", sum2);
	}
	return 0;
}