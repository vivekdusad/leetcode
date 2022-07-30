class Solution {
public:
    
    bool isUniversal(vector<int> &word,vector<int> &maxB){
        for(int i=0;i<word.size();i++){
            if(word[i]<maxB[i]) return false;
        }
        
        return true;
    }
    
    vector<int> giveFreq(string word){
        vector<int> f(26,0);
            for(int i=0;i<word.size();i++){
                f[word[i]-'a']++;
            }
        return f;
    }
    
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {        
        vector<int> maxB(26,0);        
        vector<string> result;        
        for(auto word:words2){
            vector<int> f = giveFreq(word);
            for(int i=0;i<26;i++){
                maxB[i] = max(maxB[i],f[i]);
            }
        }        
        for(auto word:words1){
            vector<int> f = giveFreq(word);            
            if(isUniversal(f,maxB)){
                result.push_back(word);
            }
        }
        return result;        
    }
};