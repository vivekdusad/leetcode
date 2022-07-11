class Solution {
public:
    bool canTransform(string start, string target) {
        int i=0;
        int j=0;
        int n = start.length();
        while(i<n or j<n){
            while(i<n and start[i]=='X') i++;
            while(j<n and target[j]=='X') j++;
            
            if(i==n or j==n){
                return i==n and j==n;
            }
            
            if(start[i] != target[j]) return false;
            
            if(start[i]=='L'){
                if(i<j) return false;
            }else if(start[i]=='R'){
                if(i>j) return false;
            }
            i++;
            j++;
        }
        return true;
    }
};