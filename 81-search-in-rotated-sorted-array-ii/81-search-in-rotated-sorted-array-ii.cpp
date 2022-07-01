class Solution {
public:
    bool isInFirstArray(vector<int> &nums,int start,int element){
        return nums[start]<=element;
    }
    bool isBinarySearchHelpful(vector<int> &nums,int start,int element){
        
        return nums[start] == element;
    }
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size()-1;
        
        while(low<=high){
            int mid = (low+high)>>1;
            cout<<mid<<endl;
            if(nums[mid]==target) return true;
            if(isBinarySearchHelpful(nums,low,nums[mid])){
                cout<<low<<" "<<nums[mid]<<endl;
                low++;
                continue;
            }
            bool isPivotArray = isInFirstArray(nums,low,nums[mid]);
            bool isTargetArray = isInFirstArray(nums,low,target);
            if(isPivotArray ^ isTargetArray){
                //they are present on the diffrent side
                if(isPivotArray){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }else {
                // if they are present on the diffrent side
                if(target>nums[mid]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        return false;
    }
};