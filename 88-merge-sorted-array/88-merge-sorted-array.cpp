class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //merge sort algorithm
        if(n==0) return;
        if(m==0){
            nums1 = nums2;
            return;
        }
        vector<int> result;
        int nums1_i=0;
        int nums2_i=0;
        while(nums1_i<m and nums2_i<n){
            if(nums1[nums1_i]<nums2[nums2_i]){//smaller
                result.push_back(nums1[nums1_i]);
                nums1_i++;
            }else if(nums1[nums1_i]==nums2[nums2_i]){//equal
                result.push_back(nums2[nums2_i]);
                result.push_back(nums1[nums1_i]);
                nums1_i++;
                nums2_i++;
            }else{//greator
                result.push_back(nums2[nums2_i]);
                nums2_i++;
            }
        }
        
        for(int i=nums1_i;i<m;i++){
            result.push_back(nums1[i]);
        }
        for(int i=nums2_i;i<n;i++){
            result.push_back(nums2[i]);
        }
        nums1 = result;
    }
};