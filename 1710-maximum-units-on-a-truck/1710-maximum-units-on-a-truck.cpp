//Greedy Solution

bool boxComparator(vector<int> a ,vector<int> b){
    if(a[1]>b[1]) return true;
    else if(a[1]==b[1] and a[0]<b[0]) return true;
    else{
        return false;
    }
}
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),boxComparator);
        int res = 0;
        for(int i=0;(i<boxTypes.size() and truckSize != 0);i++){
            if(truckSize>boxTypes[i][0]){//completly cover ho jayega
                truckSize = truckSize-boxTypes[i][0];
                res += boxTypes[i][0]*boxTypes[i][1];
            }else if(truckSize<=boxTypes[i][0]){
                
                res += truckSize*boxTypes[i][1];
                truckSize = 0;
            }
        }
        return res;
    }
};