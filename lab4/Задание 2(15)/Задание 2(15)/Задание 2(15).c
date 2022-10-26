#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void arr_rand_input(int arr[100][100], int col, int row);
int find_strings_without_zero(int arr[100][100], int row, int col);
void output_arr(int arr[100][100], int row, int col);
void arr_input_check(int arr[100][100], int col, int row);
int choice_input_check();
int input_check(int* row, int* col);
int main()
{
	int	arr[100][100], col, row, choice = 0, max_elem = 0;
	input_check(&row, &col);
	choice = choice_input_check();
	switch (choice)
	{
	case 1:
		arr_input_check(arr, col, row);
		break;
	case 2:
		arr_rand_input(arr, col, row);
		break;
	default:
		return 0;
		break;
	}
	output_arr(arr, row, col);
	printf(find_strings_without_zero(arr, row, col));
}
int input_check(int* row, int* col)
{
	printf("Enter arr cols\n");
	while (scanf_s("%d", col) == 0 || *col >= 101 || *col < 1 || getchar == '\n')
	{
		printf("Wrong input\n");
		rewind(stdin);
	}
	printf("Enter arr rows\n");
	while (scanf_s("%d", row) == 0 || *row >= 101 || *row < 1 || getchar == '\n')
	{
		printf("Wrong input\n");
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
void arr_input_check(int arr[100][100], int col, int row)
{
	for (int i = 0; i < row; i++)
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
void arr_rand_input(int arr[100][100], int col, int row)
{
	srand(time(NULL));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			arr[i][j] = rand() % 200 - 100;
		}
	}
}
void output_arr(int arr[100][100], int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d \t", arr[i][j]);
		}
		printf("\n");
	}
}
int find_strings_without_zero(int arr[100][100], int row, int col)
{
	int a=0;
	int sum = 0;
	for (int j = 0; j < col; j++)
	{
		for (int i = 0; i < col; i++) 
		{
			if (arr[i][j] != 0)
				a = 1;
		}
		if (!a) 
		{
			printf("Column %d has only zero\n", j+1);
			for (int k = 0; k < col; k++)
			{
				arr[j][k] *= -1;
				printf("%d ", arr[j][k]);
			}
			break;
		}	
	}
}