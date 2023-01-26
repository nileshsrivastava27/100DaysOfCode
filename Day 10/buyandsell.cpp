#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0;
        int minSoFar = prices[0];

        for(int i=0;i<prices.size();i++){
            minSoFar = min(minSoFar, prices[i]);

            int profit = prices[i]-minSoFar;

            maxProfit = max(maxProfit, profit);
        }
        return maxProfit;
    }
};