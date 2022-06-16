class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int row_index=-1;
        for(int i=0;i<n;i++){
            if(matrix[i][m-1]>=target){
                row_index = i;
                break;
            }
        }
        if(row_index != -1){
            return binary_search(matrix[row_index].begin(),matrix[row_index].end(),target);
        }else{
            return false;
        }
    }
};