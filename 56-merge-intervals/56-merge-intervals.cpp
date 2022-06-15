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
        for(int i=1;i<n;i++){
            if(isOverlapping(result[result.size()-1],nums[i])){
                vector<int> temp = result[result.size()-1];//last stored element
                temp[1] = max(nums[i][1],temp[1]);
                result.pop_back();
                result.push_back(temp);
            }else{
                result.push_back(nums[i]);
            }
        }
        return result;
    }
};