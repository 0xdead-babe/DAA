#include <iostream>
#include <algorithm>

using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = arr[end];
    int pIndex = start;
    for (int i = start; i < end; i++)
    {
        if (arr[i] <= pivot)
        {
            swap(arr[i], arr[pIndex]);
            pIndex++;
        }
    }
    swap(arr[pIndex], arr[end]);
    return pIndex;
}

void quickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int partitionIndex = partition(arr, start, end);
        quickSort(arr, start, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, end);
    }
}

void printArray(int arr[], int arrSize)
{
    for (int i = 0; i < arrSize; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, arrSize - 1);
    printArray(arr, arrSize);
    return 0;
}