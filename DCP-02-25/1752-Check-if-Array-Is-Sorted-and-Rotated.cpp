class Solution {
public:

    void rotate(vector<int>& nums){
        int temp = nums[nums.size()-1];
        nums.pop_back();
        nums.insert(nums.begin() + 0, temp);
    }

    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedarr(nums);
        sort(sortedarr.begin(), sortedarr.end());
        for(int i = 0;i < n;i++){
            rotate(nums);
            if( nums == sortedarr) return true;
        }
        return false;
    }
};