// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
private:
    vector<int> rowNbr = {-1,1,0,0,-1,1,1,-1};
    vector<int> colNbr = {0,0,1,-1,-1,-1,1,1};
    bool isSafe(vector<vector<char>>& grid,int row,int col,vector<vector<int>> &visited){
        int m = grid.size();
        int n = grid[0].size();
        
        if(row<m and col<n and row>=0 and col>=0 and grid[row][col]=='1' and visited[row][col]==0){
            return true;
        }
        return false;
    }
  public:
    void dfs(vector<vector<char>>& grid,int row,int col,vector<vector<int>> &visited){
        visited[row][col] = 1;
        
        for(int i=0;i<8;i++){
            int _row = row+rowNbr[i];
            int _col = col+colNbr[i];
            if(isSafe(grid,_row,_col,visited)){
                dfs(grid,_row,_col,visited);
            }
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int countofIslands = 0;
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((grid[i][j]=='1') && (visited[i][j]==0)){
                    countofIslands++;
                    dfs(grid,i,j,visited);
                }
            }
        }
        return countofIslands;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends