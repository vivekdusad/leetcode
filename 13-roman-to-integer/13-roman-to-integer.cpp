class Solution {
    int checkForExceptionalCondition(string &s,int i){
        if(s[i]=='I'){
            if(s[i+1]=='V') return 4;
            else if(s[i+1]=='X') return 9;
        }
        
        if(s[i]=='X'){
            if(s[i+1]=='L') return 40;
            else if(s[i+1]=='C') return 90;
        }
        
        if(s[i]=='C'){
            if(s[i+1]=='D') return 400;
            else if(s[i+1]=='M') return 900;
        }
        
        return INT_MIN;
    }
    void initalizeMap(unordered_map<char,int> &mp){
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
    }
public:
    int romanToInt(string s) {
        int ans =0;
        unordered_map<char,int> mp;
        initalizeMap(mp);
        for(int i=0;i<s.size();i++){
            if(i != s.size()-1 and checkForExceptionalCondition(s,i) != INT_MIN){
                ans += checkForExceptionalCondition(s,i);
                i++;
            }else{
                ans += mp[s[i]];
            }
        }
        return ans;
    }
};