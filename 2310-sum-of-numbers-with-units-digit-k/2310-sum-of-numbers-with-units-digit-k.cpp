class Solution {
public:
    int minimumNumbers(int num, int k) {
        if(num==0) return 0;
        if(num<k) return -1;
        for(int i=1;i<=10;i++){
            int x = (k*i)%10;
            if(num%10==x and k*i<=num){
                return i;
            }
        }
        return -1;
    }
};