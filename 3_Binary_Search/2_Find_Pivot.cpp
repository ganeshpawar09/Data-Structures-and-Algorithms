// [7,9,1,2,3]
// in this arr pivot is 1;

#include <iostream>
using namespace std;
int pivot(int *arr, int size)
{
    int s = 0;
    int e = size - 1;

    while (s < e)
    {
        int mid = s + (e - s) / 2;

        if (arr[mid] >= arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid;
        }
    }
    return s;
}

int main()
{
    int arr[7] = {7, 9, 10, 11, 1, 2, 3};
    cout << pivot(arr, 7) << endl;
    return 0;
}