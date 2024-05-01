// //************************************merge sort

// #include<bits/stdc++.h>
// using namespace std;

// void merge(int *arr, int start, int end)
// {
//     int mid=start+(end-start)/2;

//     int len1=mid-start+1;
//     int len2=end-mid;

//     int *arr1=new int[len1];
//     int *arr2=new int[len2];

//     int mainArrayindex=start;

//     for (int i = 0; i < len1; i++)
//     {
//         arr1[i]=arr[mainArrayindex++];
//     }
//     mainArrayindex=mid+1;
//     for (int i = 0; i < len2; i++)
//     {
//         arr2[i]=arr[mainArrayindex++];
//     }

//     int index1=0;
//     int index2=0;
//     mainArrayindex=start;

//     while (index1<len1 && index2<len2)
//     {
//         if(arr1[index1]<arr2[index2])
//             arr[mainArrayindex++]=arr1[index1++];
//         else
//             arr[mainArrayindex++]=arr2[index2++];
//     }
//     while (index1<len1)
//     {
//         arr[mainArrayindex++]=arr1[index1++];
//     }
//     while (index2<len2)
//     {
//         arr[mainArrayindex++]=arr2[index2++];
//     }

//     delete []arr1;
//     delete []arr2;

// }

// void merge_sort(int *arr, int start, int end)
// {
//     if(start>=end)
//         return ;

//     int mid= start+(end-start)/2;

//     merge_sort(arr, start, mid);
//     merge_sort(arr, mid+1, end);

//     merge(arr, start, end);

// }

// int main()
// {
//     int n=10;
//     int arr[n]={23,324,345,2,13,234,4534,64,4654,34134};
//     merge_sort(arr, 0, n-1);
//     for(auto i: arr)
//     {
//         cout<<i<<" ";
//     }

//     return 0;
// }

// // ******************************************************Quick Sort

// #include<bits/stdc++.h>
// using namespace std;

// int partition(int *arr, int start, int end)
// {
//     int temp=arr[start];
//     int count=0;
//     for (int i = start; i <=end; i++)
//     {
//         if(arr[i]<temp)
//             count++;
//     }
//     int pivot_index=start+count;
//     swap(arr[pivot_index],arr[start]);

//     int i=start;
//     int j=end;

//     while (i<pivot_index && j>pivot_index)
//     {
//         while (arr[i]<=temp)
//         {
//             i++;
//         }
//         while (arr[j]>=temp)
//         {
//             j--;
//         }
//         if(i<pivot_index && j>pivot_index)
//             swap(arr[i++],arr[j--]);
//     }
//     return pivot_index;

// }

// void quick_sort(int *arr, int start, int end)
// {
//     if(start>=end)
//         return;

//     int p =partition(arr, start, end);

//     quick_sort(arr, start, p-1);

//     quick_sort(arr, p+1, end);

// }

// int main()
// {
//     int n=10;
//     int arr[n]={23,324,345,2,13,234,4534,64,4654,34134};
//     quick_sort(arr, 0, n-1);
//     for(auto i: arr)
//     {
//         cout<<i<<" ";
//     }
//     return 0;
// }

// //****************************************************Print power set (exlude then include)

// #include<bits/stdc++.h>
// using namespace std;

// void solve(vector<vector<int>>&ans, vector<int>output, int index,vector<int>arr)
// {
//     if(index>=arr.size())
//     {
//         ans.push_back(output);
//         return;
//     }
//     // exclude
//     solve(ans,output, index+1, arr);
//     // include
//     int element= arr[index];
//     output.push_back(element);
//     solve(ans, output, index+1, arr);
// }

// int main()
// {
//     vector<int>arr={1,2,3};
//     vector<vector<int>>ans;
//     vector<int>output;
//     int index=0;
//     solve(ans, output, index, arr);
//     for (int  i = 0; i < ans.size(); i++)
//     {
//         for (int j = 0; j < ans[i].size(); j++)
//         {
//             cout<<ans[i][j]<<" ";
//         }cout<<endl;
//     }
//     return 0;
// }

// // ************************************include then exclude
// #include<bits/stdc++.h>
// using namespace std;

// void solve(vector<vector<int>>&ans, vector<int>output, int index,vector<int>arr)
// {
//     if(index>=arr.size())
//     {
//         ans.push_back(output);
//         return;
//     }
//     // include
//     int element= arr[index];
//     output.push_back(element);
//     solve(ans, output, index+1, arr);
//     output.pop_back();
//     // exclude
//     solve(ans,output, index+1, arr);

// }

// int main()
// {
//     vector<int>arr={1,2,3};
//     vector<vector<int>>ans;
//     vector<int>output;
//     int index=0;
//     solve(ans, output, index, arr);
//     for (int  i = 0; i < ans.size(); i++)
//     {
//         for (int j = 0; j < ans[i].size(); j++)
//         {
//             cout<<ans[i][j]<<" ";
//         }cout<<endl;
//     }
//     return 0;
// }

// // *********************************print subset whose sum ==k;

// #include<bits/stdc++.h>
// using namespace std;

// void solve(vector<vector<int>>&ans, vector<int>output, int index,vector<int>arr,int sum)
// {
//     if(index>=arr.size())
//     {
//         if(sum==0)
//             ans.push_back(output);
//         return;
//     }
//     // include

//     int element= arr[index];
//     if(element<=sum)
//     {
//         output.push_back(element);
//         sum=sum-element;
//         solve(ans, output, index+1, arr,sum);
//         sum=sum+element;
//         output.pop_back();
//     }
//     // exclude
//     solve(ans,output, index+1, arr,sum);

// }

// int main()
// {
//     vector<int>arr={1,2,3,4,5,6,7,8,9,10};
//     vector<vector<int>>ans;
//     vector<int>output;
//     int index=0;
//     int sum=20;
//     solve(ans, output, index, arr,sum);
//     for (int  i = 0; i < ans.size(); i++)
//     {
//         for (int j = 0; j < ans[i].size(); j++)
//         {
//             cout<<ans[i][j]<<" ";
//         }cout<<endl;
//     }
//     return 0;
// }

// //******************************use same index infinite time

// #include<bits/stdc++.h>
// using namespace std;

// void solve(vector<vector<int>>&ans, vector<int>output, int index,vector<int>arr,int sum)
// {
//     if(index>=arr.size())
//     {
//         if(sum==0)
//             ans.push_back(output);
//         return;
//     }
//     // include

//     int element= arr[index];
//     if(element<=sum)
//     {
//         output.push_back(element);
//         sum=sum-element;
//         solve(ans, output, index, arr,sum);
//         sum=sum+element;
//         output.pop_back();
//     }
//     // exclude
//     solve(ans,output, index+1, arr,sum);

// }

// int main()
// {
//     vector<int>arr={2,3,6,7};
//     vector<vector<int>>ans;
//     vector<int>output;
//     int index=0;
//     int sum=7;
//     solve(ans, output, index, arr,sum);
//     for (int  i = 0; i < ans.size(); i++)
//     {
//         for (int j = 0; j < ans[i].size(); j++)
//         {
//             cout<<ans[i][j]<<" ";
//         }cout<<endl;
//     }
//     return 0;
// }

// //**********************************sum of subset
// #include<bits/stdc++.h>
// using namespace std;

// void solve(vector<int>&ans, vector<int>output, int index,vector<int>arr)
// {
//     if(index>=arr.size())
//     {
//         int sum=0;
//         for(auto i: output)
//             sum=sum+i;
//         ans.push_back(sum);
//         return;
//     }
//     // include
//     int element= arr[index];
//     output.push_back(element);
//     solve(ans, output, index+1, arr);
//     output.pop_back();

//     // exclude
//     solve(ans,output, index+1, arr);

// }

// int main()
// {
//     vector<int>arr={2,3};
//     vector<int>ans;
//     vector<int>output;
//     int index=0;
//     solve(ans, output, index, arr);
//     sort(ans.begin(),ans.end());
//     for (int  i = 0; i < ans.size(); i++)
//     {
//         cout<<ans[i]<<" ";
//     }cout<<endl;
//     return 0;
// }

//  //***********************************************************************input contain multiple same elements and we neeed no duplicate ans
// #include<bits/stdc++.h>
// using namespace std;
// void solve(vector<int>arr,vector<vector<int>>& ans, vector<int>output, int index, int target)
// {
//     if(target==0)
//     {
//         ans.push_back(output);
//         return;
//     }
//     for(int i= index; i<arr.size(); i++)
//     {
//         if(i>index && arr[i]==arr[i-1])continue;
//         if(arr[index]>target)break;
//         output.push_back(arr[i]);
//         solve(arr, ans, output, i+1, target-arr[i]);
//         output.pop_back();
//     }
// }

// int main()
// {
//     vector<int> arr={1,2,2,2,5};
//     vector<vector<int>>ans;
//     vector<int>output;
//     int sum=5;
//     solve(arr, ans, output, 0,sum);
//      for (int  i = 0; i < ans.size(); i++)
//     {
//         for (int j = 0; j < ans[i].size(); j++)
//         {
//             cout<<ans[i][j]<<" ";
//         }cout<<endl;
//     }
//     return 0;
// }

// //********************************** intput contain multiple same elmenets print subset no repeative ans;

// #include<bits/stdc++.h>
// using namespace std;
// void solve(vector<int>arr,vector<vector<int>>& ans, vector<int>output, int index)
// {
//     ans.push_back(output);

//     for(int i= index; i<arr.size(); i++)
//     {
//         if(i>index && arr[i]==arr[i-1])continue;
//         output.push_back(arr[i]);
//         solve(arr, ans, output, i+1);
//         output.pop_back();
//     }
// }

// int main()
// {
//     vector<int> arr={1,2,2};
//     vector<vector<int>>ans;
//     vector<int>output;
//     solve(arr, ans, output, 0);
//      for (int  i = 0; i < ans.size(); i++)
//     {
//         for (int j = 0; j < ans[i].size(); j++)
//         {
//             cout<<ans[i][j]<<" ";
//         }cout<<endl;
//     }
//     return 0;
// }

// //***********************************************print all permutations

// #include<iostream>
// #include<vector>
// using namespace std;

// void solve(vector<vector<int>>&ans,int index,vector<int>arr)
// {
//     if(index>=arr.size())
//     {
//         ans.push_back(arr);
//         return;
//     }
//     for (int i= index; i < arr.size(); i++)
//     {
//         swap(arr[index],arr[i]);
//         solve(ans, index+1, arr);
//     }

// }

// int main()
// {
//     vector<int>arr={1,2,3};
//     vector<vector<int>>ans;
//     int index=0;
//     solve(ans,index, arr);
//     for (int  i = 0; i < ans.size(); i++)
//     {
//         for (int j = 0; j < ans[i].size(); j++)
//         {
//             cout<<ans[i][j]<<" ";
//         }cout<<endl;
//     }
//     return 0;
// }

#include <iostream>
using namespace std;

void merge(int *arr, int low, int mid, int high)
{
    int left = low;
    int right = mid + 1;
    int *arr1 = new int[high - low + 1];
    int tempInd = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            arr1[tempInd++] = arr[left++];
        }
        else
        {
            arr1[tempInd++] = arr[right++];
        }
    }
    while (left <= mid)
    {
        arr1[tempInd++] = arr[left++];
    }
    while (right <= high)
    {
        arr1[tempInd++] = arr[right++];
    }
    int mainInd = low;
    for (int i = 0; i < high - low + 1; i++)
    {
        arr[mainInd++] = arr1[i];
    }
    delete[] arr1;
}

void mergeSort(int *arr, int low, int high)
{
    if (low >= high)
        return;

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);

    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int left = low;
    int right = high;

    while (left < right)
    {
        while (arr[left] <= pivot && left < high)
        {
            left++;
        }
        while (arr[right] > pivot && right > low)
        {
            right--;
        }
        if (left < right)
            swap(arr[left], arr[right]);
    }
    swap(arr[low], arr[right]);
    return right;
}

void quickSort(int *arr, int low, int high)
{
    if (low >= high)
        return;

    int p = partition(arr, low, high);

    quickSort(arr, low, p);
    quickSort(arr, p + 1, high);
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