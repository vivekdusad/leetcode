class Solution {
private:
    void findCombinationSum(vector<int> nums,int index,int target,vector<int> &temp,vector<vector<int>> &ans){
         if(target==0){
            ans.push_back(temp);
             return;
        }
        if(index<nums.size() and target<nums[index]){
            return;
        }
        
        for(int i=index;i<nums.size();i++){
            //pick that number
            if(i != index and nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            findCombinationSum(nums,i+1,target-nums[i],temp,ans);
            //do not pick that number
            temp.pop_back();            
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        
        findCombinationSum(nums,0,target,temp,ans);
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};
/*
*/