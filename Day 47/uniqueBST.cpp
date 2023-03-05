#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int numTrees(int N) {
        vector<int> dp(N+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for(int n=2; n<=N; n++) {
            int ans = 0;
        
            for(int i=1; i<=n ;i++) {
                ans += dp[i-1] * dp[n-i];
            }

            dp[n] = ans;
        }
        return dp[N];
    }
};