class Solution {
public:
    bool checkForDivisiblity(vector<int> &nums,int num){
        for(auto it:nums) if(it%num !=0) return false;        
        return true;
    }
    int minOperations(vector<int>& nums, vector<int>& B) {
        int gcdofB=B[0];
        for(auto numDiv:B) gcdofB = gcd(gcdofB,numDiv);
        
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            if(gcdofB%nums[i]==0){
                return i;
            }
        }
        return -1;
    }
};