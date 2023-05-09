#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        
	unordered_map<int, int> mp;

	for(int i=0; i<nums.size(); i++) {
		if(mp.count(nums[i]) > 0 && abs(mp[nums[i]] - i) <= k)
			return true;
		mp[nums[i]] = i;
	}
	return false;
}
};