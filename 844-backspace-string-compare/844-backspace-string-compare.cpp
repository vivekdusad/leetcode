class Solution {
public:
    bool backspaceCompare(string s, string t) {
        vector<char> a;
        vector<char> b;
        int n1= s.length();
        int n2 = t.length();
        for(int i=0;i<n1;i++){
            if(a.size()>0 and s[i]=='#'){
                a.pop_back();
            }else if(s[i]!='#'){
                a.push_back(s[i]);
            }
        }
        for(int i=0;i<n2;i++){
            if(b.size()>0 and t[i]=='#'){
                b.pop_back();
            }else if(t[i]!='#'){
                b.push_back(t[i]);
            }
        }
        n1 = a.size();
        n2 = b.size();
        cout<<n1<<" "<<n2<<endl;
        if(n1 != n2){
            return false;
        }
        int i=0;
        
        while(i<n1){
            cout<<"a[i] "<<s[i]<<" b[i] "<<b[i];
            if(a[i] != b[i]){
                return false;
            }
            i++;
        }
        return true;        
    }
};