class Solution {
    string generateKey(string s1,string s2){
        return s1+"__"+s2;
    }
   
    bool isScrambleUtil(string s1,string s2,unordered_map<string,bool> &cache){
        int n = s1.length();
        if(s1 == s2) return true;
        if(s1=="" or s2=="") return false;
        
        string key = generateKey(s1,s2);    
        //used the cached Result
        if(cache.find(key)!=cache.end()){
            return cache[key];
        }
        //Driver Code
        bool flag = false;
        for(int i=1;i<n;i++){
            //case 1
            bool case1 =isScrambleUtil(s1.substr(0,i),s2.substr(n-i),cache)==true && isScrambleUtil(s1.substr(i,n-i),s2.substr(0,n-i),cache)==true;
            //case 2
            bool case2 = isScrambleUtil(s1.substr(0,i),s2.substr(0,i),cache) && isScrambleUtil(s1.substr(i),s2.substr(i),cache);
            
            if(case1 or case2) flag = true;
        }
        //Puting the result in the cache
        return cache[key] =  flag;
    }
public:
    bool isScramble(string s1, string s2) {
        unordered_map<string,bool> cache;
        return isScrambleUtil(s1,s2,cache);
    }
};