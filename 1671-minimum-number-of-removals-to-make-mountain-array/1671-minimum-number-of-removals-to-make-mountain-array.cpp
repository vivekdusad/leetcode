class Solution {
    
int bitonic(vector<int> arr)
{
    int n = arr.size();
    // Length of increasing subarray
    // ending at all indexes
    int inc[n];
     
    // Length of decreasing subarray
    // starting at all indexes
    int dec[n];
    int i, max;
 
    // length of increasing sequence
    // ending at first index is 1
    inc[0] = 1;
 
    // length of increasing sequence
    // starting at first index is 1
    dec[n-1] = 1;
 
    // Step 1) Construct increasing sequence array
    for (i = 1; i < n; i++)
    inc[i] = (arr[i] >= arr[i-1])? inc[i-1] + 1: 1;
 
    // Step 2) Construct decreasing sequence array
    for (i = n-2; i >= 0; i--)
    dec[i] = (arr[i] >= arr[i+1])? dec[i+1] + 1: 1;
 
    // Step 3) Find the length of
    // maximum length bitonic sequence
    max = inc[0] + dec[0] - 1;
    for (i = 1; i < n; i++)
        if (inc[i] + dec[i] - 1 > max)
            max = inc[i] + dec[i] - 1;
 
    return max;
}
    
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int> LIS(n,1);
        vector<int>LDS(n,1);
        // calculate the longest increase subsequence (LIS) for every index i
        for(int i=1 ; i < n ; i++)
        {
            for(int j = 0 ; j < i ; j++)
            {
                if(nums[i] > nums[j] && LIS[j]+1 > LIS[i])
                    LIS[i] = LIS[j]+1;
            }
        }
        
		// calculate the longest decreasing subsequence(LDS) for every index i and keep track of the maximum of LIS+LDS
        int max_ele = 0;
        for(int i=n-2 ; i >= 0 ; i--)
        {
            for(int j = n-1 ; j > i ; j--)
            {
                if(nums[i] > nums[j] && LDS[j]+1 > LDS[i])
                    LDS[i] = LDS[j]+1;
            }
            
            if(LIS[i] > 1 && LDS[i] > 1) 
                max_ele = max(LIS[i]+LDS[i]-1, max_ele);
        }
        return n - max_ele;
    }
};