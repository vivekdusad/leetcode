class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> temp;
        
        for(int i=0;i<rowIndex;i++){
            temp.push_back(giveNcR(rowIndex,i));
        }
        temp.push_back(1);
        return temp;
    }
    int giveNcR(int n,int k){
        long long res=1;
        for(int i=0;i<k;i++){
            res  *= (n-i);
            res /= (i+1);
        }
        return res;
    }
};