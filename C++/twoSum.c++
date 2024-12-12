#include <iostream>
using namespace std;

int n = 10;

void bubbleSort(int arr[], int n)
{
    int i, j, temp;
    for (i = 0; i < n - 1; i++)
    {

        for (j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int n, int target, int excludeIndex)
{
    int start = 0;   // Start index
    int end = n - 1; // End index

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
    }
}

void findTargetSumIndices(int arr[], int n, int target)
{
}

int main()
{
    int arr[n] = {10, 20, 40, 12, 19, 68, 41, 42, 80, 90};

    bubbleSort(arr, n);

    cout << "Sorted Array" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int target = 60;

    findTargetSumIndices(arr, n, target);
}