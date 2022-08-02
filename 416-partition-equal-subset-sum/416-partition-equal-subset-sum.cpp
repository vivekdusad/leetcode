class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        
        if(sum %2 != 0) return false;
        int n = nums.size();
        sum = sum/2;
        vector<vector<int>> dp(n+1,vector<int>(sum+1,0));
        
        for(int i=0;i<=n;i++) dp[i][0] = 1;
        for(int i=1;i<=sum;i++) dp[0][i] = 0;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j-nums[i-1]>=0){
                    dp[i][j] = dp[i-1][j] or dp[i-1][j-nums[i-1]];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
};