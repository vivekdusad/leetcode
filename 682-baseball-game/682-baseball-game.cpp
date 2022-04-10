class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> results;
        for(int i=0;i<ops.size();i++){
            if(ops[i]== "C"){
                    results.pop_back();
                }                    
                else if(ops[i]== "D"){
                    results.push_back((results[results.size()-1])*2);
                }                    
                else if(ops[i]== "+"){
                    int a = results[results.size()-1];
                    int b = results[results.size()-2];
                    results.push_back(a+b);
                }                    
                else{
                    results.push_back(stoi(ops[i]));
                }    
                        
        }
        int ans=0;
        for(auto itr:results){
            ans += itr;
        }
        return ans;
    }
};