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

        if (arr[mid] == target && mid != excludeIndex)
        {
            return mid; // Return index if target is found and not excluded
        }
        else if (arr[mid] < target)
        {
            start = mid + 1; // Move start to mid + 1
        }
        else
        {
            end = mid - 1; // Move end to mid - 1
        }
    }
    return -1;
}

void findTargetSumIndices(int arr[], int n, int target)
{
    int used[n] = {0}; // Array to track used indices
    int found = 0;     // Flag to track if any pair is found

    for (int i = 0; i < n; i++)
    {
        if (used[i]) // Skip if this index is already used
            continue;

        int firstElement = arr[i];
        int remainingTarget = target - firstElement;

        // Search for the remaining value in the array
        int index = binarySearch(arr, n, remainingTarget, i);

        if (index != -1 && !used[index]) // Ensure the second index is also unused
        {
            cout << "Pair found at indices " << i << " " << index << endl;
            used[i] = 1;     // Mark the current index as used
            used[index] = 1; // Mark the found index as used
            found = 1;
        }
    }

    if (!found)
    {
        printf("No pairs found for the target sum.\n");
    }
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