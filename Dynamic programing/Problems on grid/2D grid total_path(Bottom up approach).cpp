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
	// tabulation method(Bottom up approach);
	int dp[m][n];
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(i==0 && j==0){
				dp[i][j]=1;
			}else{
				int right=0,down=0;
				if(i>0){
					down=dp[i-1][j];
				}
				if(j>0){
					right=dp[i][j-1];
				}
				dp[i][j]=right+down;
			}
	
		}
		
	}
	return dp[m-1][n-1];
}