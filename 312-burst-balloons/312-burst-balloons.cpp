class Solution {
public:
    int maxCoinsHelper(vector<int> &nums,int i,int j,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j] != -1)return dp[i][j];
        int max_coins = INT_MIN;
        for(int k=i;k<=j;k++){
            int coins = nums[i-1]*nums[k]*nums[j+1]+maxCoinsHelper(nums,i,k-1,dp)+maxCoinsHelper(nums,k+1,j,dp);
            max_coins = max(coins,max_coins);
        }
        return dp[i][j] =  max_coins;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,0));
        
        for(int i=n;i>=1;i--){
            for(int j =i;j<=n;j++){
                int max_coins = INT_MIN;
                for(int k=i;k<=j;k++){
                    int coins = nums[i-1]*nums[k]*nums[j+1]+dp[i][k-1]+dp[k+1][j];
                    max_coins = max(coins,max_coins);
                }
                dp[i][j] =  max_coins;
            }
        }
        return dp[1][n];
    }
};