class Solution {
public:
    bool checkForDivisiblity(vector<int> &nums,int num){
        for(auto it:nums) if(it%num !=0) return false;        
        return true;
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        map<int,int> mp;
        for(auto it:nums){
            if(mp.find(it) != mp.end()){
                mp[it]++;
            }else{
                mp[it]=1;
            }
        }
        int ans = 0;
        for(auto it:mp){
            
            bool isDiv = checkForDivisiblity(numsDivide,it.first);
            if(!isDiv){
                ans = ans+it.second;
            }else{
                break;
            }
        }
        return ans==nums.size()?-1:ans;
    }
};