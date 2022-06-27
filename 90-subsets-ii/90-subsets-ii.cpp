class Solution {
public:
    void calculate(vector<int>& nums,int index,vector<int> &temp,vector<vector<int>> &ans){
        ans.push_back(temp);
        for(int i=index;i<nums.size();i++){
            if(i != index and nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);//picking the element
            calculate(nums,i+1,temp,ans);
            temp.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        calculate(nums,0,temp,ans);
        return ans;
    }
};