class Solution {
public:
    
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum=0;
        vector<int> ans;
        unordered_map<int,int> seen;
        // for(auto it:nums) it = target-it;
        for(int i=0;i<nums.size();i++){
            if(seen.find(nums[i]) != seen.end()){
                ans.push_back(i);
                ans.push_back(seen[nums[i]]);
            }else{
                seen[target-nums[i]]=i;
            }
        }
        return ans;
    }
        
};