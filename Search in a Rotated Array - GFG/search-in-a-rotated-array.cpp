// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int search(int arr[], int l, int h, int target){
        while(l<=h){
            int mid = (l+h)>>1;
            if(target==arr[mid]) return mid;
            if(arr[l]<=arr[mid]){
                if(arr[l]<=target and arr[mid]>=target){
                    h = mid-1;
                }else{
                    l = mid+1;
                }
            }else if(arr[h]>=arr[mid]){
                if(arr[mid]<=target and arr[h]>=target){
                    l = mid+1;
                }else{
                    h = mid-1;
                }
            }
        }
        return -1;
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int A[n];
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends