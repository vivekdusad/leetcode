class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> a ={1};
        result.push_back(a);                
        for(int i=1;i<numRows;i++){
            vector<int> temp;
            temp.push_back(1);
            for(int j=1;j<i;j++){            
            temp.push_back(giveNcR(i,j));            
        }
            temp.push_back(1);
            result.push_back(temp);
        }
        return result;
    }
    int giveNcR(int n,int k){
        int res=1;
        for(int i=0;i<k;i++){
            res  *= (n-i);
            res /= (i+1);
        }
        return res;
    }
};