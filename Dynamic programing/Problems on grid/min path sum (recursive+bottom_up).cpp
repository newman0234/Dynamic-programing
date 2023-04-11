#include <bits/stdc++.h> 
using namespace std;
int find_min(int i,int j,int n,int m,vector<vector<int>>&grid,vector<vector<int>>&dp){
     if(i==n-1 and j==m-1){
        return grid[i][j];
    }
    if(i>=n || j>=m){
        return 1e9;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
   
    int right=grid[i][j]+find_min(i,j+1,n,m,grid,dp);
    int down=grid[i][j]+find_min(i+1,j,n,m,grid,dp);
    return dp[i][j]=min(right,down);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here.
    // int n=grid.size();
    // int m=grid[0].size();
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    // int ans=find_min(0,0,n,m,grid,dp);
    // return ans;
    int n=grid.size();
    int m=grid[0].size();
    int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 and j==0){
                dp[i][j]=grid[i][j];
            }else{
                int right=1e9,down=1e9;
                if(i>0){
                    down=grid[i][j]+dp[i-1][j];
                }
                if(j>0){
                    right=grid[i][j]+dp[i][j-1];
                }
                dp[i][j]=min(right,down);
            }
        }
    }
    return dp[n-1][m-1];
}