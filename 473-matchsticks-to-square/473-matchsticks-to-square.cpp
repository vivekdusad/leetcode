class Solution {
public:
    bool makeSquareHelper(vector<int> &matchSticks,int n,vector<int> &squares,int target){
        if(n == matchSticks.size()){
            for(int i=1;i<4;i++){
                if(squares[i-1]!=squares[i]) return false;
            }
            return true;
        }
                
        for(int i=0;i<4;i++){
            if(squares[i]+matchSticks[n]>target) continue;
            squares[i] += matchSticks[n];
            if(makeSquareHelper(matchSticks,n+1,squares,target)) return true;
            squares[i] -= matchSticks[n];
        }
        
        return false;
    }    
    
    bool makesquare(vector<int>& matchSticks) {
        int n = matchSticks.size();
        vector<int> squares(4,0);
        int sum=0;
        sum = accumulate(matchSticks.begin(),matchSticks.end(),0);
        if(sum%4 !=0) return false;
        sort(matchSticks.rbegin(),matchSticks.rend());
        return makeSquareHelper(matchSticks,0,squares,sum/4);
    }
};