class Solution {
public:
    int findMin(vector<int>& arr) {
       int low = 0;
        int n  = arr.size();
        int high = n-1;
        if(high==0) return arr[0];
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)>>1;
            if(mid-1>=0 and mid+1<n and arr[mid-1]>arr[mid] and arr[mid+1]>arr[mid]) return arr[mid];
            
            
            if(arr[low]<=arr[mid]){
                ans = min(ans,arr[low]);
                low = mid+1;
            }else if(arr[low]>arr[mid]){
                high = mid-1;
                ans = min(arr[mid],ans);
            }
        }
        return ans; 
    }
};