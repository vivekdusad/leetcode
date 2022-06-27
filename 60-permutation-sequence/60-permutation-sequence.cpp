class Solution {
public:
    string getPermutation(int n, int k) {
        //generate number
        string s="";
        for(int i=1;i<=n;i++){
            s += to_string(i);
        }
        //1234
        for(int i=1;i<k;i++){
            s = nextPermutation(s);
        }
        return s;
    }
    string nextPermutation(string s){
        int breakPoint=-1;
        for(int i=s.size()-1;i>=0;i--){
            int a = s[i]-'0';
            int b = s[i+1]-'0';
            if(b>a){
               breakPoint = i;
                break;
            }
        }
        if(breakPoint==-1){
            sort(s.begin(),s.end());
            return s;
        }
        for(int i = s.size()-1;i>0;i--){
            if((s[i]-'0')>(s[breakPoint]-'0')){
                swap(s[i],s[breakPoint]);
                reverse(s.begin()+breakPoint+1,s.end());
                break;
            }
        }
        return s;
    }
};