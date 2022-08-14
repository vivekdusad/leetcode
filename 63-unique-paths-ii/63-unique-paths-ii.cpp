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
        vector<int> prev(n+1,0);
        prev[1] =1;
        for (int i = 1; i <= m; i++){
            vector<int> curr(n+1,0);
            for (int j = 1; j <= n; j++){
                if (!matrix[i - 1][j - 1]) curr[j] = prev[j] + curr[j - 1];
            }
            prev =curr;
        }
        return prev[n];
    }
};