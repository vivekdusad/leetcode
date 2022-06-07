class Solution {
private:
    
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> rows_seen(n,-1);
        vector<int> columns_seen(m,-1);        
        //matrix[m][n]
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0){
                    rows_seen[j]=0;
                    columns_seen[i]=0;
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rows_seen[j]==0||columns_seen[i]==0){
                    matrix[i][j]=0;
                }
            }
        }
        return;
        
    }
    
};