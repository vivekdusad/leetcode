class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char> hash;
        int count = 0;
        for(int i=0;i<key.length();i++){
            if(key[i]==' '){
                hash[key[i]] = ' ';
            }
            else if(hash.find(key[i]) == hash.end()){
                hash[key[i]] = count+'a';
                count++;
            }
        }        
        string s="";
        for(auto c:message){
            if(c==' '){
                s =s+" ";
            }
            else if(hash.find(c) != hash.end()){
                s =s+hash[c];
            }
        }
        
        return s;
    }
};