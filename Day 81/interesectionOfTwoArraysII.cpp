#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    
    vector<int> ans;
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

        int i = 0;
        int n = nums1.size();
        int m = nums2.size();
        int j = 0;
        while (i < n && j < m)
        {

            if (nums1[i] == nums2[j])
            {
                
                ans.push_back(nums1[i]);
                i++;
                j++;
                // break;
            }

            else if (nums1[i] < nums2[j])
            {
                i++;
            }

            else
            {
                j++;
            }
        }
        return ans;
    }
};