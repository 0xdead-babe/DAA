#include <iostream>
#include <algorithm>

using namespace std;

void merge(int lArr[], int lSize, int rArr[], int rSize, int a[])
{
    int i = 0, j = 0, k = 0;
    // compare and place in correct place
    while (i < lSize && j < rSize)
    {
        if (lArr[i] < rArr[j])
        {
            a[k] = lArr[i];
            i++;
            k++;
        }
        else
        {
            a[k] = rArr[j];
            j++;
            k++;
        }
    }
    // fill the remaining part of an array
    while (i < lSize)
    {
        a[k] = lArr[i];
        i++;
        k++;
    }
    while (j < rSize)
    {
        a[k] = rArr[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int arrSize)
{
    if (arrSize < 2)
        return;

    int mid = arrSize / 2;
    int l[mid], r[arrSize - mid];
    // there is only one element in an array

    // divide array into two parts
    // fill array elements in left and right array
    for (int i = 0; i < mid; i++)
    {
        l[i] = arr[i];
    }

    for (int i = mid; i < arrSize; i++)
    {
        r[i - mid] = arr[i];
    }

    mergeSort(l, mid);
    mergeSort(r, arrSize - mid);
    merge(l, mid, r, arrSize - mid, arr);
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
    mergeSort(arr, arrSize);
    printArray(arr, arrSize);
    return 0;
}