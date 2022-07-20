class Solution {
public:
    int find(vector<vector<int>> &pos,char &c,int last){
        int l = 0;
        int r = pos[c-'a'].size()-1;
        int ans=-1;
        
        while(l<=r){
            int mid = (l+r)>>1;
            if(pos[c-'a'][mid]>last){
                ans = pos[c-'a'][mid];
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>> pos(26);
        for(int i=0;i<s.size();i++){
            pos[s[i]-'a'].push_back(i);
        }
        int cnt = 0;
        
        for(auto wr:words){
            int last=-1;
            int flag =0;
            for(int i=0;i<wr.size();i++){
                last = find(pos,wr[i],last);                
                if(last==-1){
                    flag=1;
                    break;
                }
            }
            if(flag==0){
                cnt++;
            }
        }
        return cnt;
    }
};


// can user unordered_map to store the index
//can itreate over the array to find the words if match
// we can for every word we can itreate 
//Time Complecity O(n)*O(K)