class Solution {
public:
    string greatestLetter(string s) {
        vector<int> seen;
       for(int i=0;i<s.length();i++){
            for(int j=i+1;j<s.length();j++){
                if(abs(s[i]-s[j]) ==32){
                     seen.push_back(s[i]);
                }
            } 
       }
        sort(seen.begin(),seen.end());
        if(seen.size() != 0){
             string s2(1,seen.back()-32);
            return s2;
        }
        else{
            return "";
        }
        
    }
};