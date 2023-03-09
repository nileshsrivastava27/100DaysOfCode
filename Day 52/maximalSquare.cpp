#include<iostream>
#include<vector>
using namespace std;


    int solve(vector<vector<char>>& matrix, int i, int j, int &maxi, vector<int>& dp, int n)
    {

        if(i>=matrix.size() || j>=matrix[0].size())
            return 0;

        if(dp[n]!= -1)
            return dp[n];

        int bottom = solve(matrix, i+1 , j, maxi, dp, n);
        int diagnol = solve(matrix, i+1, j+1, maxi, dp ,n);
        int right = solve(matrix, i, j+1, maxi, dp ,n);

        if(matrix[i][j] =='1'){

            int side = 1+ min(min(bottom, diagnol), right);
            maxi = max(maxi, side);
            return dp[n] = side;
        }

        else{
            return 0;
        }
    }


    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        int n = matrix.size();
        vector<int> dp(matrix.size()+1, -1);
        solve(matrix, 0, 0, maxi, dp ,n);
        return maxi;
    }