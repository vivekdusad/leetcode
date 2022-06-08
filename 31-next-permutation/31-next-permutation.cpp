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
        int i = n-2;
        for(int i=n-2;i>=0;i--){
            if(nums[i]>=nums[i+1]){
                continue;
            }else{
                for(int j=n-1;j>i;j--){
                    if(nums[i]<nums[j]){
                        swap(nums[i],nums[j]);
                        reverse(nums.begin()+i+1,nums.end());
                        return;
                    }
                }
            }
        }
        sort(nums.begin(),nums.end());
    }
    
};