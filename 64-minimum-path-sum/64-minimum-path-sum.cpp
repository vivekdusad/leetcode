class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<int> prev(m,0);

		for(int i=0;i<n;i++){
            vector<int> curr(m,0);
			for(int j=0;j<m;j++){
				if(i==0 && j==0)
					curr[j] = grid[i][j];
				else{
					int left = 1e9, right=1e9;
					if(i>0)
						left = prev[j];
					if(j>0)
						right = curr[j-1];
					curr[j] = grid[i][j] + min(left, right);
				}
			}
            prev = curr;
		}
		return prev[m-1];
	}
};
/*
class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>>dp(n, vector<int>(m, 0));

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(i==0 && j==0)
					dp[i][j] = grid[i][j];
				else{
					int left = 1e9, right=1e9;
					if(i>0)
						left = dp[i-1][j];
					if(j>0)
						right = dp[i][j-1];

					dp[i][j] = grid[i][j] + min(left, right);
				}
			}
		}
		return dp[n-1][m-1];
	}
};*/