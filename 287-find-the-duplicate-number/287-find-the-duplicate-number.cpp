class Solution {
public:
    int store(vector<int> &nums,int curr){
        while(nums[nums[0]] != nums[0]){
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
    }
    int findDuplicate(vector<int>& nums) {
         while(nums[nums[0]] != nums[0]){
            swap(nums[0],nums[nums[0]]);
        }
        return nums[0];
    }
};