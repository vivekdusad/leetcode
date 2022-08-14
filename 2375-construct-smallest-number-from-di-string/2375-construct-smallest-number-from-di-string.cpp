class Solution {
public:
    string smallestNumber(string pattern) {
        string res = "",st = "";
        int n = pattern.size();
        for(int i=0;i<=n;i++){
            st.push_back(i+'1');
            if(i==n or pattern[i]=='I'){
                while(!st.empty()){
                    res.push_back(st.back());
                    st.pop_back();
                }
            }
        }
        return res;
    }
};