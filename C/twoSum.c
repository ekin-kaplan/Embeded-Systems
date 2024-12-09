#include <stdio.h>

#define N 10 // Defining Global Variable of Array .
void bubbleSort(int *pointer[], int n);

void bubbleSort(int *pointer[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - 1 - i; j++)
        {
            if (*pointer[j] > *pointer[j + 1])
            {
                temp = *pointer[j];
                *pointer[j] = *pointer[j + 1];
                *pointer[j + 1] = temp;
            }
        }
    }
}

int main()
{

    int arr[N] = {10, 20, 40, 12, 19, 68, 41, 42, 80, 90};
    int *pointer[N];

    for (int i = 0; i < N; i++)
    {
        pointer[i] = &arr[i];
    }

    bubbleSort(pointer, N);

    // Printing sorted array
    for (int i = 0; i < N; i++)
    {
        printf("%d ", *pointer[i]);
    }
    printf("\n");

    return 0;
}
