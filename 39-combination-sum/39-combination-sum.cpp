class Solution {

private:
    void findCombinationSum(vector<int> nums,int index,int target,vector<int> &temp,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(temp);
        }
        if(target<nums[index]){
            return;
        }
        
        for(int i=index;i<nums.size();i++){
            //pick that number
            temp.push_back(nums[i]);
            findCombinationSum(nums,i,target-nums[i],temp,ans);
            //do not pick that number
            temp.pop_back();            
        }
    }
    
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        findCombinationSum(nums,0,target,temp,ans);
        return ans;
    }
};