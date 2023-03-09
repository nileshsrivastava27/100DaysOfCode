#include<iostream>
#include<vector>
using namespace std;


// 0/1 Knapsack Problem (Dynammic Programming)

int solve(vector<int>& val, vector<int>& wt, int index, int capacity)
{

    if(index == val.size() || capacity == 0)
        return 0;

    int include = 0;

    if(capacity >= wt[index])
    {
        include = val[index] + solve(val, wt, index+1, capacity-wt[index]);
    }

    int exclude = 0 + solve(val, wt, index+1, capacity);

    return max(include, exclude);

}


int solveMem(vector<int>& val, vector<int>& wt, int index, int capacity, 
vector<vector<int> >& dp, int n)
{
    if(index == val.size() || capacity == 0)
        return 0;

    if(dp[index][capacity]!=-1)
        return dp[index][capacity];

    int include = 0;

    if(capacity >= wt[index])
        include = val[index] + solveMem(val, wt, index+1, capacity-wt[index], dp ,n);

    int exclude = 0 + solveMem(val, wt, index+1, capacity, dp, n);

    return dp[index][capacity] = max(include, exclude);

    
}


int solveTab(vector<int> val, vector<int> wt, int C, int n) {
    vector<vector<int> > dp(n+1, vector<int>(C+1, 0));

    for(int index = n-1; index>=0; index--) {
        for(int capacity =0; capacity <=C; capacity++) {

            int include = 0;

            if(capacity >= wt[index])
                include = val[index] + dp[index+1][capacity-wt[index]];

            int exclude = 0 + dp[index+1][capacity];

            dp[index][capacity] = max(include, exclude);
        }
    }


    // for(int index = 0; index<=n; index++) {
    //     for(int capacity =0; capacity <=C; capacity++) {
    //         cout << dp[index][capacity] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[0][C];

}