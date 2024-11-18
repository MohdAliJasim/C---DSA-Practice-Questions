class Solution {
public:
    long long totalHours(vector<int>& piles , int h){
        long long totalH = 0;
        for(int i = 0;i < piles.size();i++){
            totalH += ceil(double(piles[i])/double(h));
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int high = INT_MIN;
        for(int i = 0 ;i < piles.size();i++){
            high = max(high, piles[i]);
        }
        int low = 1;
        while(low <= high){
            int mid = (low + high)/2;
            long long  cH = totalHours(piles, mid);
            if(cH <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};