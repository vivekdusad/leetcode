class Solution {
public:
    void reverseBtwnIndexes(vector<int>& nums,int i,int j){
        int start = i;
        int end = j;
        while(start<end){
            swap(nums[start],nums[end]);
            start++;
            end--;
        }
    }
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n<=1) return;
        int i = n-2;
        while(i>=0&&nums[i]>=nums[i+1]) i--;
        if(i>=0){
            int j = n-1;
            while(nums[i]>=nums[j]) j--;
            swap(nums[i],nums[j]);            
        }
        reverse(nums.begin()+i+1,nums.end());
    }
    
};