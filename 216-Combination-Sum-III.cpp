class Solution {
public:
    void solve(int index ,int k , int n ,vector<int>& nums, vector<vector<int>>& ans, vector<int>&temp){
        if(temp.size() == k){
            if(n == 0 ) ans.push_back(temp);
            return;
        }
        for(int i = index; i < nums.size();i++){
            temp.push_back(nums[i]);
            solve(i+1, k , n-nums[i], nums, ans, temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> nums = {1,2,3,4,5,6,7,8,9};
        solve(0,k, n ,  nums, ans, temp);
        return ans;
    }
};