#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int solve(vector<int>& potions, int& spell, long long& target)
    {
        int n = potions.size(), bestIndex = n;
        int start = 0, end = n - 1;

        while(start <= end)
        {
            int mid = start + (end - start) / 2;
            long long product = (long long)spell * potions[mid];
            
            if (product >= target)
            {
                bestIndex = mid;
                end = mid - 1;
            }

            else start = mid + 1;
        }

        return (n - bestIndex);
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        int n = spells.size();
        vector<int>result(n);

        sort(potions.begin(), potions.end());

        for (int i = 0; i < n; i++) 
            result[i] = solve(potions, spells[i], success);
        
        return result;
    }
};