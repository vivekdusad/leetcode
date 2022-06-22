class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = INT_MIN;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==curr){
                nums[i] = INT_MAX;
            }else{
                curr = nums[i];
            }
        }
        sort(nums.begin(),nums.end());
        int k=0;
        for(auto it:nums){
            if(it != INT_MAX){
                k++;
            }else{
                break;
            }
        }
        return k;
        
    }
};