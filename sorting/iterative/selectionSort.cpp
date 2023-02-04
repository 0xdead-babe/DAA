#include <iostream>
#include <algorithm>

using namespace std;

void selectionSort(int arr[], int arrSize)
{
    // by the end of the loop last index would have been sorted
    for (int i = 0; i < arrSize - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
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
    int arr[] = {2, 4, 9, 8, 6, 1};
    int arrSize = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, arrSize);
    printArray(arr, arrSize);
    return 0;
}