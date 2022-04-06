class Solution {
public:
    int threeSumMulti(vector<int>& arr, int target) {
        int mod = 1e9+7;
        long long ans=0;
        int n = arr.size();
        cout<<n<<endl;
        sort(arr.begin(), arr.end());
        for(int a=0;a<arr.size();a++)
        {
            int sum = target-arr[a];            
            int i=a+1;
            int j=n-1;
            while(i<j){
                int curr = arr[i]+arr[j];
                if(curr<sum){
                    i++;
                }else if(curr>sum){
                    j--;
                }else if(arr[i] !=arr[j]){
                    int count_a=1;
                    int count_b=1;
                    while(i+1<j and arr[i]==arr[i+1]) i++, count_a++;
                    while(j-1>i and arr[j]==arr[j-1]) j--, count_b++;
                    ans = (ans+(count_a*count_b));
                    ans = ans%mod;
                    i++, j--;
                } else {
                    ans += (j-i+1) * (j-i) / 2;
                    ans %= mod;
                    break;
                }
            }
        }
        return (int) ans;
    }
};