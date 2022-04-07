class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        if(n==1){
            return stones[0];
        }
        sort(stones.begin(),stones.end());
        int first_max = stones[n-1];
        int second_max = stones[n-2];
        stones.pop_back();
        stones.pop_back();
        stones.push_back(first_max-second_max);
       return lastStoneWeight(stones);
    }
};