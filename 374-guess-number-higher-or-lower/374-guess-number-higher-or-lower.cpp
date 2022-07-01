/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        long long low = 1;
        long long high = n;
        
       while(low<=high){
        long long mid = (low+high)>>1;
        if(guess(mid)==-1)//go on lower side
        {
         high = mid-1;   
        }else if(guess(mid)==1){
            low = mid+1;
        }else if(guess(mid)==0){
            return (int)mid;
        }
       }
        return (int)n;
    }
};