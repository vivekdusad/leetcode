class Solution {
public:
    int minCostHelper(vector<int> &cuts,int i,int j,vector<vector<int>> &dp){
        if(i>j) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int min_cost = INT_MAX;
        for(int k = i;k<=j;k++){
            int temp_cost = (cuts[j+1]-cuts[i-1])+minCostHelper(cuts,i,k-1,dp)+minCostHelper(cuts,k+1,j,dp);
            min_cost = min(temp_cost,min_cost);
        }
        dp[i][j]=  min_cost;
        return dp[i][j];
    }
    int minCost(int n, vector<int>& cuts) {
        int c = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        vector<vector<int>> dp(c+1,vector<int>(c+1,-1));
        return minCostHelper(cuts,1,c,dp);
    }
};