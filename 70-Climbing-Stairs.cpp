class Solution {
public:
    int cs(int n , vector<int>& ds){
         if(n == 0 || n == 1){
            return 1;
        }
        if(n < 0) return 0;
        if(ds[n] != -1) return ds[n];
        
        ds[n] = cs(n-1,ds) + cs(n-2,ds);
        return ds[n];
    }
    int climbStairs(int n) {
        vector<int> ds(n+1,-1);
        return cs(n,ds);
    }
};