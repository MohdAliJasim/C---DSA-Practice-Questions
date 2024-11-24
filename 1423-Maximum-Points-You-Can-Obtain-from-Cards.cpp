class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l = k-1; 
        int r = cardPoints.size()-1;
        int sum =0;
        int ans = 0;
        for(int i =0 ; i <= l ; i++){
            sum += cardPoints[i];
        }
        ans = sum;
        while(cardPoints.size()-1-r != k){
            sum -= cardPoints[l];
            sum += cardPoints[r];
            ans= max(ans, sum);
            l--;
            r--;
        }
        return ans;
    }
};