const int mod =1e9+7;
class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        
        int maxHorizontalGap = horizontalCuts[0];
        int maxVerticalGap = verticalCuts[0];
        
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        for(int i=1;i<horizontalCuts.size();i++){
            int diff = horizontalCuts[i]-horizontalCuts[i-1];
            maxHorizontalGap = max(maxHorizontalGap,diff);
        }
        
         for(int i=1;i<verticalCuts.size();i++){
            int diff = verticalCuts[i]-verticalCuts[i-1];
            maxVerticalGap = max(maxVerticalGap,diff);
        }
        
        return (1L* maxVerticalGap*maxHorizontalGap)%mod;
    }
};