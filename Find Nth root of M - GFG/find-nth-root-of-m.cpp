// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
	public:
	double multiply(double number, int n) {
        double ans = 1.0;
        for(int i = 1;i<=n;i++) {
            ans = ans * number;
        }
        return ans; 
    }
	int NthRoot(int n, int m)
	{
	    int l=1;
	    int h=m;
	    while(l<=h)
	    {
	        int mid=(l+h)/2;
	        if(pow(mid,n)==m){
	            return mid;
	        }
	        else if(pow(mid,n)>m)
	        {
	            h=mid-1;
	        }
	        else{
	            l=mid+1;
	        }
	    }
	    return -1;
	}  
	/*
	double multiply(double number, int n) {
    double ans = 1.0;
    for(int i = 1;i<=n;i++) {
        ans = ans * number;
    }
    return ans; 
}
	void getNthRoot(int n, int m) {
    double low = 1;
    double high = m;
    double eps = 1e-6; 
    
    while((high - low) > eps) {
        double mid = (low + high) / 2.0; 
        if(multiply(mid, n) < m) {
            low = mid; 
        }
        else {
            high = mid; 
        }
    }
    
    cout <<n<<"th root of "<<m<<" is "<<low<<endl; 
    
}*/
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}  // } Driver Code Ends