#include<iostream>
#include<vector>
using namespace std;


class Solution{
public:
    int solveMem(vector<vector<char>>& matrix, int i, int j, int &maxi, vector<vector<int> > &dp){

        if(i>=matrix.size() || j >= matrix[0].size())
            return 0;

        if(dp[i][j] != -1)
            return dp[i][j];
        
        int bottom = solveMem(matrix, i+1, j, maxi, dp);
        int diagnol = solveMem(matrix, i+1, j+1, maxi, dp);
        int right = solveMem(matrix, i, j+1, maxi, dp);
        
        if(matrix[i][j] == '1') {
            int side = min(bottom, min(right, diagnol)) + 1;
            maxi = max(maxi, side);
            return dp[i][j] = side;
        }
        else
        {
            return 0;
        }

    }

    int solve(vector<vector<char>>& matrix, int i, int j, int &maxi) {
        //base case
        if(i>=matrix.size() || j >= matrix[0].size())
            return 0;
        
        int bottom = solve(matrix, i+1, j, maxi);
        int diagnol = solve(matrix, i+1, j+1, maxi);
        int right = solve(matrix, i, j+1, maxi);
        
        if(matrix[i][j] == '1') {
            int side = min(bottom, min(right, diagnol)) + 1;
            maxi = max(maxi, side);
            return side;
        }
        else
        {
            return 0;
        }
    }
    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        int n = matrix.size();
        vector<vector<int> > dp(n+1, vector<int>(n+1, -1));
        solveMem(matrix, 0,0, maxi, dp);
        return maxi*maxi;
    }
};