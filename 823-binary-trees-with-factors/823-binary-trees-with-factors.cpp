#define ll long long
int MOD = 1e9+7;
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        vector<ll> dp(n,1);
        unordered_map<int,int> hash;
        for(int i=0;i<n;i++) hash[arr[i]] = i;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(arr[i]%arr[j]==0){
                    int right = arr[i]/arr[j];
                    if(hash.find(right) != hash.end()){
                        dp[i] = (dp[i]+dp[j]*dp[hash[right]])%MOD;
                    }
                }
            }
        }
        ll ans = 0;
        for(ll it:dp) ans = (ans+it)%MOD;
        return (int)ans;
    }
};