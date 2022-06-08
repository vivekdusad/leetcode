class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        vector<int> a ={1};
        vector<int> b ={1,1};
        vector<int> c = {1,2,1};
        if(numRows>=1){
            result.push_back(a);
        }
        if(numRows>=2){
            result.push_back(b);
        }
        if(numRows>=3){
            result.push_back(c);
        }
        if(numRows>3){
            for(int i=3;i<numRows;i++){
                vector<int> temp;
                vector<int> last = result[result.size()-1];
                int k=0;int j=1;
                temp.push_back(1);
                int n = last.size();
                while(j<n){
                    temp.push_back(last[k]+last[j]);
                    k++;
                    j++;
                }
                temp.push_back(1);
                result.push_back(temp);
            }
        }
        return result;
    }
};