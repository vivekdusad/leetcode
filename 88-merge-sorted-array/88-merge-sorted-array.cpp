class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //merge sort algorithm
        if(n==0) return;
        if(m==0){
            nums1 = nums2;
            return;
        }
        int i,k;
        for(i=0;i<m;i++){
             if(nums1[i]>nums2[0])
                swap(nums1[i],nums2[0]);           
            int first = nums2[0];
            for(k=1;(k<n and nums2[k]<first);k++)
                nums2[k-1] = nums2[k];
            nums2[k-1] = first;
        }
        for(k=i;k<m+n;k++){
            nums1[k] = nums2[k-m];
        }
    }
};