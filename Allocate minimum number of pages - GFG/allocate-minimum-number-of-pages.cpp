// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool isPossible(int A[],int N,int barrier,int students){
        int cnt=0;
        int totalPages = 0;
        for(int i=0;i<N;i++){
            if(totalPages+A[i]>barrier){
                cnt++;
                totalPages = A[i];
                if(totalPages>barrier) return false;
            }
            else {
                totalPages += A[i];
            }
        }
        if(cnt<students) return true;
        return false;
    }
    int findPages(int A[], int N, int M) 
    {
        int low = A[0];
        int high =0;
        for(int i=0;i<N;i++){
            low = min(low,A[i]);
            high += A[i];
        }
        while(low<=high){
            int mid = (high+low)>>1;
            if(isPossible(A,N,mid,M)){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return low;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends