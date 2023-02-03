#include<iostream>
#include<vector>
using namespace std;

    int maxProduct(vector<int>& nums) { 


        int n=nums.size();
        int i,res=INT_MIN,prod=1;
        for(i=0;i<n;i++){
            prod=prod*nums[i];
            res=max(prod,res);
            if(nums[i]==0){
                prod=1;
            }
        }
        prod=1;
        for(i=n-1;i>=0;i--){
            prod=prod*nums[i];
            res=max(prod,res);
            if(nums[i]==0){
                prod=1;
            }
        }
        return res;


    }