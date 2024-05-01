#include<iostream>
#include<vector>
using namespace std; 
bool solve(vector<int>nums, vector<int>output, int index, vector<vector<int>>&ans,int sum, int target)
{
    if(index>=nums.size())
    {
        if(sum==target)
        {
            ans.push_back(output);
            return true;
        }
        else
        {
            return false;
        }
    }

    // exclude
    if (solve(nums, output, index+1,ans,sum,target)==true)
    {
        return true;
    }

    // include
    int element=nums[index];
    sum=sum+element;
    output.push_back(element);
    if (solve(nums, output, index+1,ans,sum,target)==true)
    {
        return true;
    }
    sum=sum-element;
    return false;
}

int main()
{
    vector<int>nums={1,2,3,4,5,6,7,8,9,10};
    vector<vector<int>> ans;
    vector<int>output;
    int index=0;
    int sum=0;
    int target=15;
    solve(nums, output, index,ans,sum,target);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << endl;
    }
    return 0;
}