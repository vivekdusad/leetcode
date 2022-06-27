// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool isPalindrome(string s,int start,int end){
        while(start<=end){
           if(s[start++] != s[end--]) return false;
        }
        return true;
    }
  void funPartition(int index,string s,vector<string> &temp,vector<vector<string>> &ans){
        int n = s.size();
        if(index==n){
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<n;i++){
            if(isPalindrome(s,index,i)){
                temp.push_back(s.substr(index,i-index+1));
                funPartition(i+1,s,temp,ans);
                temp.pop_back();                
            }
        }
    }
    vector<vector<string>> allPalindromicPerms(string s) {
        vector<vector<string>> ans;
        vector<string> temp;
        funPartition(0,s,temp,ans);
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends