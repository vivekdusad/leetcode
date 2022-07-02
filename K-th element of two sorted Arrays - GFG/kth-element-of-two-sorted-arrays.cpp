// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int kthElement(int arr1[], int arr2[], int n, int m, int k)
    {
        if(m<n) return kthElement(arr2,arr1,m,n,k);
        int low = max(0,k-m);
        int high = min(k,n);
        while(low<=high){
            int curr1 = (low+high)>>1;
            int curr2 = k-curr1;
            
            int l1 = curr1==0?INT_MIN:arr1[curr1-1];
            int l2 = curr2==0?INT_MIN:arr2[curr2-1];
            
            int r1 = curr1==n?INT_MAX:arr1[curr1];
            int r2 = curr2==m?INT_MAX:arr2[curr2];
            
            if(l1<=r2 and l2<=r1){
                return max(l1,l2);
            }else if(l1>r2){
                high = curr1-1;
            }
            else{
                low = curr1+1;
            }
        }
        return 0;
        
    }
};

// { Driver Code Starts.
 
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m,k;
		cin>>n>>m>>k;
		int arr1[n],arr2[m];
		for(int i=0;i<n;i++)
			cin>>arr1[i];
		for(int i=0;i<m;i++)
			cin>>arr2[i];
		
		Solution ob;
        cout << ob.kthElement(arr1, arr2, n, m, k)<<endl;
	}
    return 0;
}  // } Driver Code Ends