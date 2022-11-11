class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> mp;
        int size = 0;
        for(int i=0;i<nums.size();i++){
            if(mp.find(nums[i]) != mp.end()){
                nums[i] = INT_MAX;
                size++;
            }else{
                mp.insert(nums[i]);
            }
        }
        sort(nums.begin(),nums.end());
        return nums.size()-size;
    }
};