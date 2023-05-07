#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int s = 0; 
        int e = people.size() - 1;
        int ans = 0;

        while (s <= e) {

            if (people[s] + people[e] <= limit)
            {
                s++;
            }
                e--;
                ans++;
        }

        return ans;
    }
};