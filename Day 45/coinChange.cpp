#include<iostream>
#include<vector>
using namespace std;


    int coinChange(vector<int>& coins, int t) {
    
    vector<int> dp(t+1, INT_MAX);

    dp[0] = 0;

    for(int target=1; target<=t;target++){
            
        int mini = INT_MAX;

        for(int i=0;i<coins.size();i++)
        {
            if(target - coins[i] >= 0)
            {
                int ans = dp[target - coins[i]];

                if(ans!=INT_MAX)
                    mini = min(1+ans, mini);    
            }
        }
        dp[target] = mini;
    }

        if(dp[t]==INT_MAX)
        {
            return -1;
        }
        
    return dp[t];
    }


    