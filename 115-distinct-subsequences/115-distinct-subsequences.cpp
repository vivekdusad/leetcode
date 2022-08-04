#define ll long long int
class Solution {
public:
    int numDistHelper(string s1,string s2,int i,int j){
        if(j==0) return 1;
        if(i==0) return 0;
        if(s1[i-1]==s2[j-1]){
            return numDistHelper(s1,s2,i-1,j)+numDistHelper(s1,s2,i-1,j-1);
        }else{
            return numDistHelper(s1,s2,i-1,j);
        }
    }
    int numDistinct(string s1, string s2) {
        int m = s1.size();
        int n = s2.size();
        cout<<m<<" "<<n<<endl;
        int mod = 1e9+7;
        // return numDistHelper(s,t,i,j);
        vector<vector<ll>> dp(m+1,vector<ll>(n+1));
        for(int i=0;i<=m;i++) dp[i][0] = 1;
        for(int i=1;i<=n;i++) dp[0][i] = 0;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
               if(s1[i-1]==s2[j-1]){
                   dp[i][j] = (dp[i-1][j]%mod+dp[i-1][j-1]%mod)%mod;
               }else{
                   dp[i][j] = dp[i-1][j];
               }
            }
        }
        return dp[m][n];
    }
};