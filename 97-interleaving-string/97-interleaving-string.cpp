class Solution {
public:
    bool is_InterLeave(string s1,int i,string s2,int j,string s3,int k,vector<vector<int>> &dp){
        if(i==s1.length()){
            return s2.substr(j)==s3.substr(k);
        }
        if(j==s2.length()){
            return s1.substr(i)==s3.substr(k);
        }
        //already been processed
        if(dp[i][j] !=-1){
            return dp[i][j];
        }        
        bool ans = false;
        
        if(s3[k]==s1[i] and is_InterLeave(s1,i+1,s2,j,s3,k+1,dp) or s3[k]==s2[j] and    is_InterLeave(s1,i,s2,j+1,s3,k+1,dp)){
           ans =true; 
        }
        dp[i][j] = ans;
        return ans;        
    }
    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<int>> dp(s1.length(),vector<int>(s2.length(),-1));
        if(s1.length()+s2.length()!=s3.length()){
            return false;
        }
        return is_InterLeave(s1,0,s2,0,s3,0,dp);
        
    }
};