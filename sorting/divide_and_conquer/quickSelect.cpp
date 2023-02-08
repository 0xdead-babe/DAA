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

    swap(arr[end], arr[pIndex]);
    return pIndex;
}

int quickSelect(int arr[], int start, int end, int k)
{
    // kth smallest element to find
    if (start < end)
    {
        // returns the kth smallest element
        int pIndex = partition(arr, start, end);

        if (k == pIndex + 1)
            return arr[pIndex];

        if (k < pIndex)
            return quickSelect(arr, start, pIndex - 1, k);
        else
            return quickSelect(arr, pIndex + 1, end, k);
    }

    return 1e9;
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    cout << quickSelect(arr, 0, arrSize - 1, 2);
    return 0;
}