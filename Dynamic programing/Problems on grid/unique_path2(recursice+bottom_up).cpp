long long int mod=1e9+7;
int find_path(int i,int j,int n,int m,vector<vector<int>>mat,vector<vector<int>>&dp){
    if(i>=n || j>=m){
        return 0;
    }
    if(mat[i][j]==-1){
        return 0;
    }
    if(i==n-1 and j==m-1){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    long long int right=find_path(i,j+1,n,m,mat,dp);
    long long int down=find_path(i+1,j,n,m,mat,dp);
    return dp[i][j]=((right%mod)+(down%mod))%mod;
}


int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // // Write your code here
    // if(mat[n-1][m-1]==-1){
    //     return 0;
    // }
    // vector<vector<int>>dp(n,vector<int>(m,-1));
    // int ans=find_path(0,0,n,m,mat,dp);
    // return ans;
    int dp[n][m];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0 and j==0){
                dp[i][j]=1;
            }else if(mat[i][j]==-1){
                dp[i][j]=0;
            }else{
                int down=0,right=0;
                if(i>0){
                    right=dp[i-1][j];
                }
                if(j>0){
                    down=dp[i][j-1];
                }
                dp[i][j]=(down+right)%mod;
            }
        }
    }
    return dp[n-1][m-1];
}