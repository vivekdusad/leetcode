class Solution {
public:
    int superEggDrop(int e, int f) {
        vector<vector<int>> dp(e+1,vector<int>(f+1,0));
        for(int i=0;i<=f;i++) dp[1][i] = i;
        for(int i=0;i<=e;i++) dp[i][0] = 0;
        for(int i=0;i<=e;i++) dp[i][1] = 1;
        for(int i=0;i<=f;i++) dp[0][i] = 0;
        
        for(int i=2;i<=e;i++){
            for(int j=2;j<=f;j++){
                int l = 1;
                int r = j;
                int ans = INT_MAX;
                while(r-l>=2){
                    int mid = (l+r)/2;
                    int t1 = dp[i-1][mid-1];//increasing curve
                    int t2 = dp[i][j-mid];//decreasing curve
                    
                    if(t1>t2){
                        r = mid;
                    }else if(t1<t2){
                        l = mid;
                    }else{
                        l = mid;
                        r = mid;
                    }
                }
                ans = min(max(dp[i-1][l-1],dp[i][j-l]),max(dp[i-1][r-1],dp[i][j-r]))+1;
                dp[i][j] = ans;
            }
        }
        return dp[e][f];
    }
};