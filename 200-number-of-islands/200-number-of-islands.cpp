class Solution {
private:
    vector<int> rowNum = {-1,1,0,0};
    vector<int> colNum = {0,0,1,-1};
    
    bool isSafe(vector<vector<char>> &grid,int m,int n,int row,int col){
        if(row>=0 and col>=0 and row<n and col<m and grid[row][col]=='1'){
            return true;
        }
        return false;
    }
    void DfsRec(vector<vector<char>> &grid,vector<vector<int>> &visited,int &row,int &col){
        visited[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<4;i++){
            int r = row+rowNum[i];
            int c = col+colNum[i];
            
            if(isSafe(grid,m,n,r,c) and visited[r][c]==0){
                
                DfsRec(grid,visited,r,c);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int noOfContComp =0;
        for(int row=0;row<n;row++){
            for(int col=0;col<m ; col++){
                if(visited[row][col]==0 and grid[row][col]=='1'){
                    noOfContComp++;
                    DfsRec(grid,visited,row,col);
                }
            }
        }
        return noOfContComp;
    }
};