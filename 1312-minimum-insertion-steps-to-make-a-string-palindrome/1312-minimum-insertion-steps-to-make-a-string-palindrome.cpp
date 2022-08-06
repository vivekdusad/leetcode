class Solution {
    int lcs(string s1,string s2){
        int n1 = s1.size();
        int n2 = s2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        
        for(int i=0;i<=n1;i++){
            for(int j=0;j<=n2;j++){
                if(i==0 or j==0) dp[i][j] = 0;
                else if(s1[i-1]==s2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                }else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[n1][n2];
    }
public:
    int minInsertions(string s) {
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return s.size()-lcs(s,s2);
    }
};