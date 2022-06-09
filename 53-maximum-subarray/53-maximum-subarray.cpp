//kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> max_cache(nums.size());
        max_cache[0] = nums[0];
        for(int i=1;i<nums.size();i++){
            max_cache[i] = max(nums[i]+max_cache[i-1],nums[i]);
        }
        int ans = max_cache[0];
        for(int i=1;i<nums.size();i++){
            ans = max(ans,max_cache[i]);
        }
        return ans;
    }
    /*
    int n = nums.size();
        int max_array[n];
        max_array[0]=nums[0];
        for(int i=1;i<n;i++){
            max_array[i] = max(max_array[i-1]+nums[i],nums[i]);
        }
        int ans = max_array[0];
        for(int i=1;i<n;i++){
            ans = max(ans,max_array[i]);
        }
        return ans;*/
};