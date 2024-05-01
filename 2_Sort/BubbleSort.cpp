#include <iostream>
using namespace std;

void bubble_sort(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
            for (int k = 0; k < size; k++)
            {
                cout << arr[k] << " ";
            }
            cout << endl;
        }
    }
}

int main()
{
    int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    bubble_sort(arr, 10);

    return 0;
}