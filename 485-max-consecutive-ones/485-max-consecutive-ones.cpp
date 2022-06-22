class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_count = 0;
        int ans = 0;
        for(auto it:nums){
            if(it==0){
                ans = 0;
            }else{
                ans++;
            }
            max_count = max(ans,max_count);
        }
        return max_count;
    }
};