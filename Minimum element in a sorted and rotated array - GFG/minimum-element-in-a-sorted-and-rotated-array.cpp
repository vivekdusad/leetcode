// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int findMin(int arr[], int n){
        int low = 0;
        // int n  = arr.size();
        int high = n-1;
        int ans = INT_MAX;
        while(low<=high){
            int mid = (low+high)>>1;
            if(arr[mid-1]>arr[mid] and arr[mid+1]>arr[mid]) return arr[mid];
            
            
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

// { Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}  // } Driver Code Ends