class Solution {
    vector<string> table = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> mp;
        int ans =0;
        for(int i=0;i<words.size();i++){
            string res = "";
            for(int j=0;j<words[i].size();j++){
                res = res+ table[words[i][j]-'a'];
            }
            cout<<res<<endl;
            if(mp.find(res) == mp.end()){
                ans++;
                mp.insert(res);
            }
        }
        return ans;
    }
};