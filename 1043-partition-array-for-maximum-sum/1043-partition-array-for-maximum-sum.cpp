int mod = 1e9+7;
#define ll long long
class Solution {
    int maxSumHelper(vector<int> &nums,int k,int i,vector<ll> &dp){
        int n = nums.size();
        //Base Condtion
        if(i==n) return 0;
        if(dp[i] != -1) return dp[i];
        //Recursion
        int maxi =INT_MIN,len=0,maxAns = INT_MIN;
        for(int j=i;j<min(n,i+k);j++){
            len++;
            maxi = max(maxi,nums[j]);
            ll sum = (maxi*len)%mod +(maxSumHelper(nums,k,j+1,dp))%mod;
            maxAns = max(maxAns,(int)sum);
        }
         dp[i]  = maxAns%mod;
        return dp[i];
    }
public:    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<ll> dp(n+1,0);
        
        for(int i=n-1;i>=0;i--){
            int maxi =INT_MIN,len=0,maxAns = INT_MIN;
            for(int j=i;j<min(n,i+k);j++){
                len++;
                maxi = max(maxi,arr[j]);
                ll sum = ((maxi*len)%mod +(dp[j+1])%mod)%mod;
                maxAns = max(maxAns,(int)sum);
            }
             dp[i]  = maxAns%mod;
        }
        return dp[0];
    }
};