class Solution {
public:
    int findPaths(int m,int n,int i,int j){
        if(i==m-1 and j ==n-1) return 1;
        if(i==m or j==n) return 0;        
        int dp[m][n];
        dp[m-1][n-1]=1;
        for(int i=0;i<n;i++) dp[m-1][i]=1;
        for(int i=0;i<m;i++) dp[i][n-1]=1;
        
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                dp[i][j] = dp[i+1][j]+dp[i][j+1];
            }
        }
        return dp[0][0];
    }
    int uniquePaths(int m, int n) {
        int N = m+n-2;
        int r = m-1;
        double res = 1;
        for(int i=1;i<=r;i++){
            res = res*(N-r+i);
            res = res/(i);
        }
        return (int)res;
    }
    
    /*
    int N = n + m - 2;
    int r = m - 1; 
    double res = 1;            
    for (int i = 1; i <= r; i++)
    res = res * (N - r + i) / i;
    return (int)res;*/
};