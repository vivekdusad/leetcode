class Solution {
public:
    bool binarySearch(vector<int> nums,int start,int end,int target){
        if(start==end and nums[start]==target) return true;
        bool result=false;
        if(start<end){
            int mid = (start+end)/2;            
            if(nums[mid]>target){
                result = result or binarySearch(nums,start,mid,target);
            }else if(nums[mid]<target){
                result = result or binarySearch(nums,mid+1,end,target);
            }else{
                result=true;
                cout<<mid<<endl;
            }
        }
        return result;
    }
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
            return binarySearch(matrix[row_index],0,m-1,target);
        }else{
            return false;
        }
    }
};