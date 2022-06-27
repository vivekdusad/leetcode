class Solution {
public:
    string getPermutation(int n, int k) {
        //generate number
        int fact =1;
        vector<int> nums;
        for(int i=1;i<n;i++){
            fact *= i;
            nums.push_back(i);
        }
        //123
        nums.push_back(n);
        //1234
        k = k-1;
        string ans = "";
        while(true){
            ans = ans + to_string(nums[k/fact]);
            nums.erase(nums.begin()+k/fact);
            if(nums.size()==0){
                return ans;
            }
            k = k%fact;
            fact = fact/nums.size();
        }
    }
    
};