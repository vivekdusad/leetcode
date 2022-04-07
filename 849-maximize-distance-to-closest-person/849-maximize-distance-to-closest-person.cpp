typedef vector<int> vi;
class Solution {
public:
    int maxDistToClosest(vi &seats)
    {
        int n =seats.size();
        vi left(n,n);
        vi right(n,n);
        
        for(int i=0;i<n;i++){
            if(seats[i] ==1) left[i]=0;
            else if(i>0) left[i] = left[i-1]+1;
        }
        
        for(int i=n-1;i>=0;i--){
            if(seats[i]==1) right[i]=0;
            else if(i<n-1) right[i] = right[i+1]+1;
        }
        int ans =INT_MIN;
        for(int i=0;i<n;i++){
            if(seats[i]==0){
             ans = max(ans,min(left[i],right[i]));
            }
        }
        return ans;
        
    }
};