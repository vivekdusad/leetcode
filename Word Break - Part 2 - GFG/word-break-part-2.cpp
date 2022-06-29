// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool checkifWordPresent(vector<string>& words,string s){
        for(auto word:words){
            if(word==s) return true;
        }
        return false;
    }
    
    void solve(string s,vector<string>& words,vector<string> &ans,string temp){
        if(s==""){
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<s.size();i++){
            bool isPresent = checkifWordPresent(words,s.substr(0,i+1));
            if(isPresent){
               solve(s.substr(i+1),words,ans,(temp==""?s.substr(0,i+1):temp+" "+s.substr(0,i+1)));
            }
        }
    }
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string> ans;
        string temp;
        solve(s,dict,ans,temp);
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends