#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        
        int n = nums.size();
        int countP = 0, countN = 0;

        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                countP++;

            else if(nums[i]<0)
                countN++;
        }

        return max(countP, countN);

    }
};