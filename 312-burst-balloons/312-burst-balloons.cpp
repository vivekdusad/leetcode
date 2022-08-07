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
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return maxCoinsHelper(nums,1,n,dp);
    }
};