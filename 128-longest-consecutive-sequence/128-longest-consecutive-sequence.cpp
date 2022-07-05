class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return 1;
        int longestStreak=0;        
        unordered_set<int> s(nums.begin(),nums.end());
        int n = nums.size();
        for(int i=0;i<n;i++){
             if (!s.count(nums[i] - 1)) {
                int currentNum = nums[i];
                int currentStreak = 1;

                while (s.count(currentNum + 1)) {
                    currentNum += 1;
                    currentStreak += 1;
                }

                longestStreak = max(longestStreak, currentStreak);
            }                     
        }
        return longestStreak;        
    }
};


//99 100 101 102 