#include <stdio.h>
#include <stdlib.h>
int inp_check_choose();
int inp_check_arrsize();
void inp_check_arrelem(int mass[], int size);
void rand_inp_check(int mass[], int size);
int find_0(int mass[], int size);
int sum_after_min(int mass[], int size);
int main()
{
    int mass[100];
    int array_size = 0;
    int option = 0;
    array_size = inp_check_arrsize();
    option = inp_check_choose();
    switch (option)
    {
    case 1:
        inp_check_arrelem(mass, array_size);
        break;
    case 2:
        rand_inp_check(mass, array_size);
        break;
    default:
        return 0;
        break;
    }
    printf("%d digits = 0\n", find_0(mass, array_size));
    printf(sum_after_min(mass, array_size));
}
int inp_check_choose()
{
    int inp;
    printf("Print 1 for manual input or 2 to random\n");
    while (scanf_s("%d", &inp) != 1 && inp != 2)
    {
        printf_s("Wrong input. Enter number 1 or 2\n");
        rewind(stdin);
    }
    return inp;
}
int inp_check_arrsize()
{
    int inp;
    printf("Enter the size of the array (the size should not exceed 100)\n");
    while (scanf_s("%d", &inp) ==0 || inp < 0|| inp>=101)
    {
        printf("Wrong input. Enter a number from 1 to 100\n");
        rewind(stdin);
    }
    return inp;
}
void inp_check_arrelem(int mass[], int size)
{
    printf("Enter the array elements\n");
    for (int i = 0; i < size; i++)
    {
        while (scanf_s("%d", &mass[i]) == 0)
        {
            printf("Wrong input.\n");
            scanf_s("%i", &mass[i]);
            rewind(stdin);
        }
    }
}
void rand_inp_check(int mass[], int size)
{
    printf("Array\n");
    for (int i = 0; i < size; i++)
    {
        mass[i] = (rand() % 10);
        printf("The %dth element of array is %d\n", i + 1, mass[i]);
    }
}
int find_0(int mass[], int size)
{
    int count0 = 0;
    for (int i = 0; i < size; ++i)
    {
        if (mass[i] == 0)
        {
            count0++;
        }
    }
    return count0;
}
int sum_after_min(int mass[], int size)
{
    int min = 0;
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (mass[min] > mass[i])
            min = i;
    }
    for (int i = min; i < size; i++)
    {
        sum += mass[i];
    }
    printf("Sum after %d element = %d\n", min + 1, sum);
    return sum;
}