#include <iostream>
using namespace std;

int partition(int *arr, int start, int end)
{
    int pivot = arr[start];
    int count = 0;

    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] < pivot)
        {
            count++;
        }
    }

    int pivotIndex = start + count;

    swap(arr[pivotIndex], arr[start]);

    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex)
    {
        while (arr[i] < arr[pivotIndex])
        {
            i++;
        }
        while (arr[j] > arr[pivotIndex])
        {
            j++;
        }
        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i], arr[j]);
        }
    }
    return pivotIndex;
}

void quickSort(int *arr, int start, int end)
{
    if (start >= end)
    {
        return;
    }

    int p = partition(arr, start, end);

    quickSort(arr, start, p);

    quickSort(arr, p + 1, end);
}

int main()
{
    int arr[7] = {38, 27, 43, 3, 9, 82, 10};
    quickSort(arr, 0, 6);
    for (int i = 0; i < 7; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}