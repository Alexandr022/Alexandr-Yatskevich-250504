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
	printf(sum(arr, col));
}
int input_check(int* col)
{

	printf("Enter arr\n");
	while (scanf_s("%d", col) == 0 || *col >= 101 || *col < 1)
	{
		printf("Wrong input.\n");
		rewind(stdin);
	}
}
int choice_input_check()
{
	int input;
	printf("Print 1 for manually 2 to random\n");
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
		printf("Enter the elements of the %d row and cols\n", i + 1);
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
	int min = 0;
	for (int i = col / 2; i < col; i++)
	{
		for (int j = 0; j <= col / 2; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for (int i = col / 2; i < col; i++)
	{
		for (int j = 0; j <= col / 2; j++)
		{
			if (arr[i][j]%2 == 0 && min > arr[i][j])
			{
				min = arr[i][j];
			}
		}
	}
	printf("min = %d\n", min);	
}