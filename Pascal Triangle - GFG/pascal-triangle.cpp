// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

 // } Driver Code Ends
// #define ll long long
const long long m = 1e9+7;

class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n) {
        vector<long long> v(n);
        vector<long long> pre(n);
        
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(j == 0 || j == i-1)
                v[j] = 1;
                else
                {
                   v[j] = (pre[j-1]%m + pre[j]%m)%m; 
                }
            }
            pre = v;
        }
        return (v);
    }
    ll giveNcr(int n,int r){
        ll ans = 1;
        for(int i=0;i<r;i++){
            ans *= (n-i-1)%m;
            ans /= (i+1)%m;
        }
        return 1L* ans%m;
    }
    
    //4 3
};


// { Driver Code Starts.


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
  // } Driver Code Ends