#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> v;
    v = {1, 2, 2, 2, 2, 2, 7, 7, 9, 10};
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    bool res = binary_search(arr, arr + 10, 11);
    cout << res << endl;

    // lower bound is pointing first occurance or number nearer to the that number;
    int arr1[10] = {1, 2, 2, 2, 2, 2, 7, 7, 9, 10};
    int firstarr = lower_bound(arr1, arr1 + 10, 11) - arr1;
    int firstv = lower_bound(v.begin(), v.end(), 7) - v.begin();
    cout << firstarr << endl;
    cout << firstv << endl;
    // int lastocc=upper_bound(arr1,arr1+10, 7)-arr1;
    // cout<<lastocc<<endl;/

    return 0;
}

// int BinarySearch(int a[], int n, int key)
// {
//     int i = 0;
//     int j = n - 1;
//     int mid = i + (j - i) / 2;

//     while (i < j)
//     {

//         if (a[mid] == key)
//         {
//             return mid;
//         }
//         else if (a[mid] < key)
//         {
//             i = mid + 1;
//         }
//         else
//         {
//             j = mid - 1;
//         }
//         mid = i + (j - i) / 2;
//     }
//     return -1;
// }

// int main()
// {

//     int a[8] = {4, 5, 9, 11, 16, 23, 49, 81};
//     cout << BinarySearch(a, 8, 23) << endl;
// }