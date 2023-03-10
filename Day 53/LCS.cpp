#include<iostream>
#include<vector>
using namespace std;



    int solve(string &s1, string &s2, int i, int j)
    {
        if(i == s1.length() || j == s2.length())
            return 0;

        int ans = 0;

        if(s1[i] == s2[j])
            ans = solve(s1,s2, i+1, j+1);

        else{
            int op1 = solve(s1, s2, i, j+1);
            int op2 = solve(s1, s2, i+1, j);

            ans = max(op1, op2);
        }

        return ans;
    }



    int solveMem(string &s1, string &s2, int i, int j, vector<vector<int> >& dp)
    {
        if(i == s1.length() || j == s2.length())
            return 0;

        if(dp[i][j] != -1 )
            return dp[i][j];

        int ans = 0;

        if(s1[i] == s2[j])
        {
            ans = solveMem(s1, s2, i+1, j+1, dp) + 1;
        }

        else{
            

            int op1 = solveMem(s1, s2, i, j+1, dp);
            int op2 = solveMem(s1, s2, i+1, j, dp);

            ans = max(op1, op2);
        }

        return dp[i][j] = ans;

    }


    