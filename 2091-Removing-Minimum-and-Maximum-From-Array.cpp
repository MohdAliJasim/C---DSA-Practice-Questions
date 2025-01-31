class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = 0;
        int maxi = 0;
        for(int i = 0;i < nums.size();i++){
            if(nums[mini] > nums[i]){
                mini = i;
            }
            if(nums[maxi] < nums[i]) maxi = i;
        }

        int ini = min (maxi, mini);
        int last = max(maxi , mini);
        int n = nums.size();
        int ans1 = last + 1;
        int ans2 = n-ini;
        int ans3 = (ini + 1) + (n - last);

        return min(ans1, min(ans2,ans3));
    }
};