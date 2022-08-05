class Solution {
public:
    bool isMatch(string s, string p) {
        int s1 = s.size();
        int s2 = p.size();
        vector<vector<bool>>dp(s2+1,vector<bool>(s1+1));
        for(int i=0;i<=s2;i++){
            for(int j=0;j<=s1;j++){
                if(i==0&&j==0) dp[i][j]=true;
                else if(i==0) dp[i][j]=false;
                else if(j==0){
                    if(p[i-1] == '*'&&i-2>=0){
                        dp[i][j]=dp[i-2][j];
                    }
                    else{
                        dp[i][j]=false;
                    }
                }
                else{
                    if(p[i-1]=='.' or p[i-1] == s[j-1]){
                        dp[i][j]=dp[i-1][j-1];
                    }                    
                    else if(p[i-1]=='*' and i-2>=0){
                        dp[i][j] = dp[i-2][j];
                        if(p[i-2]==s[j-1] or p[i-2]=='.'){
                            dp[i][j] = dp[i][j] or  dp[i][j-1];
                        }                        
                    }                    
                    else{
                        dp[i][j]=false;
                    }
                }
            }
        }
        return dp[s2][s1];
    }
};