class Solution {
public:
    bool isPowerOfFour(int n) {
        long long checker = 4;

        for(int i =0 ;i < INT_MAX; i++){
            checker = pow(4,i);
            if(checker > INT_MAX) return false;
            if(checker == n) return true;
        }
        return false;
    }
};