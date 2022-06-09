//kadane's Algorithm
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_ele = nums[0],sum=0;
        for(auto i:nums)
        {
            sum += i;
            max_ele = max(max_ele,sum);
            if(sum<0) sum=0;
        }
        return max_ele;
    }
};