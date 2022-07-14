class Solution {
private:
    vector<int> rowNum = {-1,1,0,0};
    vector<int> colNum = {0,0,1,-1};
    vector<int> offset = {-1,0,1,0,-1};
    bool isSafe(vector<vector<char>> &grid,int m,int n,int row,int col){
        if(row>=0 and col>=0 and row<n and col<m and grid[row][col]=='1'){
            return true;
        }
        return false;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int noOfIslands =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m ; j++){
                if(grid[i][j]=='1'){
                    grid[i][j] = '0';
                    noOfIslands++;
                    queue<pair<int,int>> todos;
                    todos.push({i,j});
                    while(!todos.empty()){
                        auto todo = todos.front();
                        todos.pop();
                        for(int k=0;k<4;k++){
                            int r = todo.first+offset[k];
                            int c = todo.second+offset[k+1];
                            if(isSafe(grid,m,n,r,c)){
                                grid[r][c] ='0';
                                 todos.push({r, c});
                            }
                        }
                    }
                }
            }
        }
        return noOfIslands; 
    }
};