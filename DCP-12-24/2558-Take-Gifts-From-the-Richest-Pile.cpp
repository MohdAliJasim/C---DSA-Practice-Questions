class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long ans = 0;
        int n = gifts.size();
        for(int i = 0;i < k ;i++){
            sort(gifts.begin(),gifts.end());
            int num = sqrt(gifts[n-1]);
            gifts[n-1] = num;
        }

        for(int gift : gifts) ans += gift;

        return ans;
    }
};