class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        if(nums.size()<3) return result;
        //O(n^2)
        
        sort(nums.begin(),nums.end());
        vector<int> ans(3);
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                int target = -nums[i]-nums[j];
                bool isFound = binary_search(nums.begin()+j+1,nums.end(),target);                
                if(isFound){
                    ans[0]=nums[i];
                    ans[1]=nums[j];
                    ans[2]=target;
                    result.push_back(ans);
                    while(j<(nums.size()-1) and nums[j+1]==ans[1]) j++;
                }
                
            }
            while(i<(nums.size()-1) and nums[i+1]==nums[i]) i++;
        }
        return result;
    }
};