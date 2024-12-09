/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return \t     -1 if num is higher than the picked number
 *\t\t\t      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int low = 0;
        int high  = n;
        while(low <= high){
            long long mid = low + (high-low)/2;

            if(guess(mid) == 0) return mid;
            if(guess(mid) == -1) high = mid-1;
            else low = mid+1;
        }
        return -1;
    }
};