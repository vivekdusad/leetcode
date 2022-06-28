class Solution {
public:
    bool isSafe(vector<string> &nums,int row,int col,int n){
        int dupRow = row;
        int dupCol = col;
        
        //check in the diagonal left hand side
        while(row>=0 and col>=0){
            if(nums[row][col]=='Q') return false;            
            row--;
            col--;
        }
        row = dupRow;
        col = dupCol;
        //check in the diagonal right hand side
        while(row>=0 and col<n){
            if(nums[row][col]=='Q') return false;
            row--;
            col++;
        }
        row = dupRow;
        col = dupCol;
        //check in the column
        while(row>=0){
            if(nums[row][col]=='Q') return false;
            row--;
        }        
        return true;
    }
    void solve(vector<string> &nums,int n,int row,vector<vector<string>> &ans){
        if(row==n){
            ans.push_back(nums);
            return;
        }
        if(row>n) return;
        
        for(int col=0;col<n;col++){
            if(isSafe(nums,row,col,n)){
                nums[row][col] = 'Q';
                solve(nums,n,row+1,ans);
                nums[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> temp(n);
        string s(n,'.');
        for(int i=0;i<n;i++){
            temp[i] = s;
        }
        vector<vector<string>> ans;
        solve(temp,n,0,ans);
        return ans;
    }
};