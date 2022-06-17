class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int count1=0;
        int count2=0;
        int ele1=-1;
        int ele2=-1;
        for(auto it:nums){
            if(it==ele1){
                count1++;
            }else if(it==ele2){
                count2++;    
            }
            else if(count1==0){
                count1++;
                ele1 = it;
            }else if(count2==0){
                count2++;
                ele2=it;
            }else{
                count1--;
                count2--;
            }
        }
        vector<int> result;
        count1=0;
        count2=0;
        for(auto it:nums){
            if(it==ele1){
                count1++;
            }else if(it==ele2){
                count2++;
            }
        }
        if(count1>(nums.size()/3)){
            result.push_back(ele1);
        }
        if(count2>(nums.size()/3)){
            result.push_back(ele2);
        }
        return result;
    }
    
};