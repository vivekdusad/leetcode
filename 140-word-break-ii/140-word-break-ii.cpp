class Solution {
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
    vector<string> wordBreak(string s, vector<string>& dict) {
        vector<string> ans;
        string temp;
        solve(s,dict,ans,temp);
        return ans;
    }
};