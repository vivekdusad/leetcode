// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	    void solve(string s,int l,int r,vector<string> &ans){
	        if(l==r){
	            ans.push_back(s);
	            return;
	        }
	        if(l>r) return;
	        
	        for(int i=l;i<=r;i++){
	            if(i != l and s[i]==s[i-1]) continue;
	            swap(s[l],s[i]);
	            solve(s,l+1,r,ans);
	            swap(s[l],s[i]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    vector<string> ans;
		    solve(S,0,S.size()-1,ans);
		    sort(ans.begin(),ans.end());
		    return ans;
		}
};



// { Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}
  // } Driver Code Ends