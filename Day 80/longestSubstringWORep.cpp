#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int n= s.size();
        int ans=0;
        int initial=INT_MIN;
        vector<int> v(200,-1);

        for(int i=0; i<n; i++)
        {
            if(v[s[i]]>initial)
            {
                initial= v[s[i]];
            }

            v[s[i]]=i;

            ans= max(ans,i-initial);
        }
        
        return ans;
    }
};