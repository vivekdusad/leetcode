class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;        
        long long nm=n;
        if(nm<0) nm  = -1*nm;
        while(nm){
            if(nm %2){
                ans = ans*x;
                nm = (nm-1);                
            }else{
               x = x*x;
                nm = nm/2; 
            }
        }
        if(n<0) ans= (double)(1.0)/(double)(ans); 
        return ans;
    }
    /*
     double ans = 1.0;
  long long nn = n;
  if (nn < 0) nn = -1 * nn;
  while (nn) {
    if (nn % 2) {
      ans = ans * x;
      nn = nn - 1;
    } else {
      x = x * x;
      nn = nn / 2;
    }
  }
  if (n < 0) ans = (double)(1.0) / (double)(ans);
  return ans;*/
};