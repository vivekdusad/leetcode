class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int num = abs(nums[i]);
            if(nums[num]<0){
                return abs(num);
            }else{
                nums[num] = -nums[num];
            }
        }
        return -1;
    }
};