class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        vector<int> l2r(n,1);
        vector<int> r2l(n,1);
        
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                l2r[i]=l2r[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(nums[i+1]<nums[i]){
                r2l[i]= r2l[i+1]+1;
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += max(l2r[i],r2l[i]);
        }
        return ans;
    }
};