class Solution {
public:
    int store(vector<int> &nums,int curr){
        if(curr==nums[curr])
            return curr;
        int next = nums[curr];
        nums[curr] = curr;
        return store(nums,next);
    }
    int findDuplicate(vector<int>& nums) {
        return store(nums,0);
    }
};