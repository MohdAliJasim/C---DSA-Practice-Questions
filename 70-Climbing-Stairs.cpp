class Solution {
public:
    // int cs(int n , vector<int>& ds){
    //      if(n == 0 || n == 1){
    //         return 1;
    //     }
    //     if(n < 0) return 0;
    //     if(ds[n] != -1) return ds[n];
        
    //     ds[n] = cs(n-1,ds) + cs(n-2,ds);
    //     return ds[n];
    // }
    int climbStairs(int n) {
        vector<int> ds(n+1);
        // ds[0] = 1;
        // ds[1] = 1;
        int prev1 = 1;
        int prev2 = 1;
        for(int i = 2 ; i<= n; i++){
            //ds[i] = ds[i-1] + ds[i-2];
            int curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
       // return ds[n];
      //  return cs(n,ds);
    }
};