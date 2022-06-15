bool sortPair(vector<int> &a, vector<int> &b){
        return a[0]<b[0];
    }
class Solution {
public:
    bool isOverlapping(vector<int>&a,vector<int>&b){
        return a[1]>=b[0];
    }    
    vector<vector<int>> merge(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>> result;
        sort(nums.begin(),nums.end(),sortPair);
        result.push_back(nums[0]);
        for(auto it:nums){
            vector<int> temp = result.back();
            if(isOverlapping(temp,it)){
                //last stored element
                temp[1] = max(it[1],temp[1]);
                result.pop_back();
                result.push_back(temp);
            }else{
                result.push_back(it);
            }
        }
        return result;
    }
};