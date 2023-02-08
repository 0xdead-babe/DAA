#include <iostream>
#include <algorithm>

using namespace std;

int partition(int arr[], int start, int end)
{
    srand(time(NULL));
    int random = start + rand() % (end - start + 1);
    swap(arr[random], arr[start]);
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

void rQuickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        int p = partition(arr, start, end);
        rQuickSort(arr, start, p - 1);
        rQuickSort(arr, p + 1, end);
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
    int arr[] = {1, 8, 7, 6, 2};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    rQuickSort(arr, 0, arrSize - 1);
    printArray(arr, arrSize);
    return 0;
}