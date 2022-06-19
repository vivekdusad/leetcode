class Solution {
public:
    string greatestLetter(string s) {
        unordered_set<char> seen;
        for(int i=0;i<s.size();i++){
            seen.insert(s[i]);
        }
        for(int i=90;i>=65;i--){
            if(seen.find(i+32)!= seen.end() and seen.find(i) != seen.end()){
                string s2(1,i);
                return s2;
            }
        }
        return "";
    }
};