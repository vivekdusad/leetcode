class Solution {
public:
    int robHelper(vector<int> &nums,int n){
        if(n==0) return 0;
        
        if(n-2>=0){
            return max(robHelper(nums,n-2)+nums[n-1],robHelper(nums,n-1));
        }else{
            return nums[n-1];
        }
    }
    int rob(vector<int>& nums) {
        // return robHelper(nums,nums.size());
        int n = nums.size();
        vector<int> dp(n+1,0);
        
        for(int i=1;i<=n;i++){
            if(i-2>=0){
                dp[i]=  max(dp[i-2]+nums[i-1],dp[i-1]);
            }else{
                dp[i] = nums[i-1];
            }
        }
        return dp[n];
    }
};