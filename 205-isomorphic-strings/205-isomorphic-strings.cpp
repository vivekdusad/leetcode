class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m1;
        unordered_map<char,char> m2;
        bool isMatched = true;
        
        for(int i=0;i<s.size();i++){
            if(m1.find(s[i]) != m1.end()){
                if(m1[s[i]] != t[i]) isMatched = false;
            }else{
                m1[s[i]] = t[i];
            }
            
            
            if(m2.find(t[i]) != m2.end()){
                if(m2[t[i]] != s[i]) isMatched = false;
            }else{
                m2[t[i]] = s[i];
            }
            
        }
        return isMatched;
    }
};