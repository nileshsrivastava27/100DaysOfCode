#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void firstOcc(vector<int>&nums,int target,vector<int>&ans){
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(nums[mid]==target){
                ans[0]=mid;
                // search left side to find the first occurrence
                high=mid-1;
            }
            else if(nums[mid]<target)   low=mid+1;
            else high=mid-1;
        }
    }
    void lastOcc(vector<int>&nums,int target,vector<int>&ans){
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=(low+high)>>1;
            if(nums[mid]==target){
                ans[1]=mid;
                //search right side to find the last occurrence
                low=mid+1;
            }
            else if(nums[mid]<target)   low=mid+1;
            else high=mid-1;
        }
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2,-1);
        firstOcc(nums,target,ans);
        lastOcc(nums,target,ans);
        return ans;
    }
};