#include <iostream>
using namespace std;

bool is_max(int *arr, int size, int cows, int mid)
{
    int coordinate = arr[0];
    int count = 1;
    for (int i = 0; i < size; i++)
    {
        if ((arr[i] - coordinate) >= mid)
        {
            count++;
            coordinate = arr[i];
        }
    }
    if (count != cows)
        return 0;
    else
        return 1;
}

int solve(int *arr, int size, int cows)
{
    int low = 1;
    int high = arr[size - 1] - arr[0];
    int ans = 0;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (is_max(arr, size, cows, mid))
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}

int main()
{
    int arr[5] = {1, 3, 5, 7, 9};
    cout << solve(arr, 5, 3) << endl;
    return 0;
}