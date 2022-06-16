class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count=0;
        int element=-1;
        for(auto it:nums){
            if(count==0){
                count++;
                element= it;
            }else if(element==it){
                count++;
            }else{
                count--;
            }
        }
        return element;
    }
};