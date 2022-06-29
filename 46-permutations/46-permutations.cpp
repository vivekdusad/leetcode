class Solution {
public:
    void solve(vector<int>& nums,vector<bool> &freq, vector<int> &temp,vector<vector<int>> &ans){
        int n = nums.size();
        if(temp.size()==n){
            ans.push_back(temp);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(!freq[i]){
                freq[i] = true;
                temp.push_back(nums[i]);
                solve(nums,freq,temp,ans);
                freq[i] = false;
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<bool> freq(nums.size(),false);
        vector<int> temp;
        solve(nums,freq,temp,ans);
        return ans;
    }
};