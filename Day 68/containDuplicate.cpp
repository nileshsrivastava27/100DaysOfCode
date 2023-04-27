#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        unordered_set<int> m;

        for(int idx = 0; idx < nums.size(); idx++) {

            if(m.count(nums[idx]))
                return true;

            m.insert(nums[idx]);
        }
        return false;
    }
};