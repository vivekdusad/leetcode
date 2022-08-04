class Solution {
public:
    int lcs(string s1,string s2){
        int m = s1.size();
        int n = s2.size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(s1[i-1]==s2[j-1]){
                    dp[i][j] = 1+dp[i-1][j-1];
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
    bool isSubsequence(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m==0) return true;
        if(n==0) return false;
        int l = lcs(s,t);
        if(l==m or l==n) return true;
        else return false;
    }
};