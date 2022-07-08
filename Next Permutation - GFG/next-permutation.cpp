// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int breakPoint = INT_MIN;
        for(int i= N-2;i>=0;i--){
            if(arr[i]<arr[i+1]){
                breakPoint = i;
                break;
            }
        }
        if(breakPoint==INT_MIN){
            sort(arr.begin(),arr.end());
            return arr;
        }
        
        for(int i=N-1;i>=0;i--){
            if(arr[i]>arr[breakPoint]){
                swap(arr[i],arr[breakPoint]);
                reverse(arr.begin()+breakPoint+1,arr.end());
                break;
            }
        }
        
        return arr;
    }
};

//1 2 5 4 3
//1 3 5 4 2
//1 3 2 4 5

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends