class Solution {
    bool isAllStars(string & S1, int i) {

     // S1 is taken in 1-based indexing
      for (int j = 1; j <= i; j++) {
        if (S1[j - 1] != '*')
          return false;
      }
      return true;
    }
public:
    bool isMatch(string S2, string S1) {
         int n = S1.size();
         int m = S2.size();

        vector < bool > prev(m+1, false);
        
        prev[0] = true;
         for (int j = 1; j <= m; j++) {
            prev[j] = false;
          }
        
          for (int i = 1; i <= n; i++) {
            vector<bool> curr(m+1, false);
            curr[0] = isAllStars(S1, i);
            for (int j = 1; j <= m; j++) {
              if (S1[i - 1] == S2[j - 1] || S1[i - 1] == '?')
                curr[j] = prev[j - 1];
              else {
                if (S1[i - 1] == '*')
                  curr[j] = prev[j] | curr[j - 1];
                else curr[j] = false;
              }
            }
            prev = curr;
          }
        return prev[m];
    }
};