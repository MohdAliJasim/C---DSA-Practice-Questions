class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0;
        int sum =0;
        for(int num : nums){
            if(num == 1){
                sum++;
            }
            else{
                sum = 0;
            }
            maxi = max(sum,maxi);
        }
        return maxi;
    }
};