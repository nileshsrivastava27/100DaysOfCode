#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:

    int solveTab(vector<int> arr, int n)
{

    vector<int> dp(n+2, 0);

    //int* dp = new int[n+1];

    //for(int i=0;i<n;i++)      dynammic allocation for array
    // {
    //     dp[i] = 0;
    // }

    for(int index = n-1;index>=0;index--)
    {
        int incl = arr[index] + dp[index+2];
        int excl = 0 + dp[index+1];

        dp[index] = max(incl, excl);
    }

    return dp[0];
}

    int rob(vector<int>& nums) {

        int n = nums.size();
        return solveTab(nums, n);
    }
};