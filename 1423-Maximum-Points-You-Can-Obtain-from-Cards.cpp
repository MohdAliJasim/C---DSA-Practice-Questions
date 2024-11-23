class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = 0; 
        int r = cardPoints.size()-1;
        int lr = k-1;
        int rl = r;
        int sum =0;
        int ans = 0;
        for(int i =l ; i <= lr ; i++){
            sum += cardPoints[i];
        }
        ans = sum;
        while(r-rl != k){
            sum -= cardPoints[lr];
            sum += cardPoints[rl];
            ans= max(ans, sum);
            lr--;
            rl--;
        }
        return ans;
    }
};