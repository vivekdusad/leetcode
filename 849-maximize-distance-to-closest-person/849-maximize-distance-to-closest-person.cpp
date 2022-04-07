class Solution {
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int i = 0;
        int j = 1;
        int n = seats.size();
        int ans = INT_MIN;
        while(seats[i]==0) i++, j++;
        ans = max(ans, i);
        while (j < n)
        {
            if (seats[j] == 1)
            {
                int mid = (j - i) / 2;
                ans = max(ans, mid );
                i = j;
            }
            j++;
        }
        return max(ans, n-i-1);
    }
};