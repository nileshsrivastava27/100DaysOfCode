#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
    vector<pair<int, string>> v;
    int n=heights.size();
    
    for (int i = 0; i < n; i++)
        v.push_back({heights[i], names[i]});

    sort(v.begin(),v.end());
    vector<string> ans;

    for (int i = n-1; i >=0; i--)
        ans.push_back(v[i].second);
    return ans;
    }
};