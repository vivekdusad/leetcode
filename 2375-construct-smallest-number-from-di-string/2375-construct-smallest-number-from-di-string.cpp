class Solution {
public:
    int dfs(string& p, int i, int n, int mask) {
    if (i > p.size())
        return n;
    int res = INT_MAX, last = n % 10, increment = i == 0 || p[i - 1] == 'I';
    for (int d = 1; d <= 9; ++d)
        if ((mask & (1 << d)) == 0 && d > last == increment)
            res = min(res, dfs(p, i + 1, n * 10 + d, mask + (1 << d)));               
    return res;
}
    string smallestNumber(string pattern) {
        return to_string(dfs(pattern,0,0,0));
    }
};