class Solution {
public:
    int partition(vector<int> &nums,int l,int h){
        int pivot = nums[h];
        int i=l-1;
        for(int j=l;j<h;j++){
            if(nums[j]<pivot){
                i++;
                swap(nums[i],nums[j]);
                
            }
        }
        swap(nums[i+1],nums[h]);
        return i+1;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int left = 0, right = nums.size() - 1, kth;
        int n = nums.size();
        while (1) {
        int idx = partition(nums, left, right);
        if (idx ==n- k ) {
            kth = nums[idx];
            break;
        }
        if (idx < n-k ) {
            left = idx + 1;
        } else {
            right = idx - 1;
        }
    }
    return kth;
    }
};