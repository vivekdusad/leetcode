class Solution {
public:
    void generatePermultation(vector<int> &nums,int l,int r, vector<vector<int>> &ans){
        if(l==r){
            ans.push_back(nums);
            return;
        } 
        if(l>r) return;
        
        for(int i=l;i<=r;i++){
            swap(nums[l],nums[i]);
            generatePermultation(nums,l+1,r,ans);
            swap(nums[l],nums[i]);
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        generatePermultation(nums,0,nums.size()-1,ans);
        return ans;
    }
};