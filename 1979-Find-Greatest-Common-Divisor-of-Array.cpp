class Solution {
public:
    int gcd(int a , int b){
        if(a == 0) return b;
        if(b == 0) return a;

        if(a > b){
            return gcd(a%b,b);
        }
        else return gcd(b%a,a);
    }
    int findGCD(vector<int>& nums) {
       int mini = INT_MAX;
       int maxi  = INT_MIN;

       for(auto a : nums){
        mini = min(mini , a);
        maxi = max(maxi, a);
       }
        return gcd(mini, maxi);
    }
};