#include <iostream>
using namespace std;

int binarySearch(int *arr, int size, int target)
{
    int low = 0, high = size - 1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] > target)
        {

            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return -1;
}
int binarySearch(int *arr, int size, int target, int low, int high)
{
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }
    else if (arr[mid] > target)
    {
        return binarySearch(arr, size, target, low, mid - 1);
    }
    else
    {
        return binarySearch(arr, size, target, mid + 1, high);
    }
}

int main()
{
    int arr[5] = {3, 5, 6, 7, 9};
    cout << binarySearch(arr, 5, 9) << endl;
    cout << binarySearch(arr, 5, 9, 0, 4) << endl;
}