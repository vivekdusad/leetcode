class Solution {
private:
    vector<int> offset = {1,0,-1,0,1};
    bool isSafe(vector<vector<char>> &grid,vector<vector<int>> &visited,int row,int col){
        int m = grid.size();
        int n = grid[0].size();
        return (row>=0 and col>=0 and row<m and col<n and grid[row][col]=='O');
    }
    
    void DFS(vector<vector<char>> &grid,vector<vector<int>> &visited,int row,int col){
        grid[row][col] = '#';
        for(int i=0;i<4;i++){
            int _row  = row+offset[i];
            int _col = col+offset[i+1];
            
            if(isSafe(grid,visited,_row,_col)){
                
                DFS(grid,visited,_row,_col);
            }
        }
    }
    
public:
    void solve(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            if(grid[0][i]=='O' and visited[0][i]==0){
                DFS(grid,visited,0,i);
            }
            if(grid[m-1][i]=='O' and visited[m-1][i]==0){
                DFS(grid,visited,m-1,i);
            }
        }
        
        for(int i=0;i<m;i++){
            if(grid[i][0]=='O'){
                DFS(grid,visited,i,0);
            }
            if(grid[i][n-1]=='O'){
                DFS(grid,visited,i,n-1);
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='#'){
                    grid[i][j] = 'O';
                }
                else if(grid[i][j]=='O'){
                    grid[i][j]='X';
                }
            }
        }
        
    }
};