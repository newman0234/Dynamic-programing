#include <bits/stdc++.h> 
int all_paths(int i,int j,int m,int n){
	
	if(i==m-1 and j==n-1){
		return 1;
	}
	if(i>=m or j>=n){
		return 0;
	}
	int right=all_paths(i,j+1,m,n);
	int down=all_paths(i+1,j,m,n);
	return right+down;
	
}
int uniquePaths(int m, int n) {
	// Write your code here.
	return all_paths(0,0,m,n);
}