class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> result;
        for(auto word:words){
            unordered_map<char,char> loTab;
            unordered_map<char,char> revTab;
            bool isMatched = true;
            for(int i=0;i<pattern.size();i++){
                if(revTab.find(pattern[i]) != revTab.end()){
                    if(revTab[pattern[i]] != word[i]) isMatched = false;
                }else{
                    revTab[pattern[i]] = word[i];
                }
                
                if(loTab.find(word[i]) != loTab.end()){
                    if(loTab[word[i]] != pattern[i]) isMatched = false;
                }else{
                    loTab[word[i]]= pattern[i];
                }
            }
            if(isMatched){
                result.push_back(word);
            }
        }
        return result;
    }
};