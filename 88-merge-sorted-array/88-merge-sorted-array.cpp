class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //merge sort algorithm
        if(n==0) return;
        if(m==0){
            nums1 = nums2;
            return;
        }
        int gap = ceil((float)(n + m) / 2);
        while(gap>0){
            int i=0;
            int j = gap;
            while(j<(m+n)){
                if(j<m and nums1[i]>nums1[j]){
                    swap(nums1[i],nums1[j]);
                }
                else if(j>=m and i<m and nums1[i]>nums2[j-m]){
                    swap(nums1[i],nums2[j-m]);                    
                }else if(j>=m and i>=m and nums2[i-m]>nums2[j-m]){
                    swap(nums2[i-m],nums2[j-m]);
                }
                i++;
                j++;
            }
            if (gap == 1) {
                 gap = 0;
            } else {
                gap = ceil((float) gap / 2);
            }
        }
        for(int k=m;k<n+m;k++){
            nums1[k]=nums2[k-m];
        }
        
    }
    /*
    int gap = ceil((float)(n + m) / 2);
  while (gap > 0) {
    int i = 0;
    int j = gap;
    while (j < (n + m)) {
      if (j < n && ar1[i] > ar1[j]) {
        swap(ar1[i], ar1[j]);
      } else if (j >= n && i < n && ar1[i] > ar2[j - n]) {
        swap(ar1[i], ar2[j - n]);
      } else if (j >= n && i >= n && ar2[i - n] > ar2[j - n]) {
        swap(ar2[i - n], ar2[j - n]);
      }
      j++;
      i++;
    }
    if (gap == 1) {
      gap = 0;
    } else {
      gap = ceil((float) gap / 2);
    }
  }*/
};