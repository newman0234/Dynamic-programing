#include <bits/stdc++.h> 
int all_paths(int i,int j,int m,int n,int dp[][15]){
	
	if(i==m-1 and j==n-1){
		return 1;
	}
	if(i>=m or j>=n){
		return 0;
	}
	if(dp[i][j]!=-1){
		return dp[i][j];
	}
	int right=all_paths(i,j+1,m,n,dp);
	int down=all_paths(i+1,j,m,n,dp);
	return dp[i][j]=right+down;
	
}
int uniquePaths(int m, int n) {
	// Write your code here.
	int dp[15][15];
	for(int i=0;i<15;i++){
		for(int j=0;j<15;j++){
			dp[i][j]=-1;
		}
	}
	return all_paths(0,0,m,n,dp);
}