#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int res = 0;
        int left = 0;
        int right = height.size()-1;
        // max area function to calculate max area.

        while(left<=right)
        {
        int temp = (right-left) * min(height[left], height[right]);

        res = max(res, temp);

        if(height[left] <= height[right])
            left++;
        else
            right--;
        }
        return res;
    }
};