class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = INT_MIN;
        int k=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==curr){
                nums[i] = INT_MAX;
            }else{
                k++;
                curr = nums[i];
            }
        }
        sort(nums.begin(),nums.end());
        return k;
    }
};