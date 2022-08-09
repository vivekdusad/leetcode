class PalindromeChecker{
    string s;
public:
    PalindromeChecker(string s){
        this->s = s;
    }
    bool check(){
        int i = 0;
        int j = s.length();
        while(i<=j){
            if(s[i] != s[j]) return false;
        i++;
        j--;
        }
        return true;
    }
};
class Solution {
    bool isPalindrome(string &s,int i,int j){
        while(i<j){
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int minCutHelper(int i,string &s,vector<int> &dp){
        int n = s.length();
        if(i==n) return 0;       
        if(dp[i] != -1) return dp[i];
        int minCost = INT_MAX;        
        for(int j=i;j<n;j++){
            if(isPalindrome(s,i,j)){
                int cost = 1+minCutHelper(j+1,s,dp);
                minCost= min(minCost,cost);
            }
        }
        return dp[i] = minCost;
    }
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n,-1);
        minCutHelper(0,s,dp);
        return dp[0]-1;
    }
};