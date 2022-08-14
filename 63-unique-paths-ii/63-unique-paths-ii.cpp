class Solution {
    int mod = 1e9+7;
public:
    int uniquePathHelper(vector<vector<int>> &matrix,int i,int j,int m,int n){
        
        if(i>=m) return 0;
        if(j>=n) return 0;
        if(matrix[i][j]==1)return 0;
        if(i==m-1 and j==n-1) return 1;
        
        int res = uniquePathHelper(matrix,i+1,j,m,n) + uniquePathHelper(matrix,i,j+1,m,n);
        
        
        return res;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int> > dp(m + 1, vector<int> (n + 1, 0));
        dp[0][1] = 1;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (!matrix[i - 1][j - 1])
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        return dp[m][n];
    }
};