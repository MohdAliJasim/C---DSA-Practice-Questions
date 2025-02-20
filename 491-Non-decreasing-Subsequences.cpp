class Solution {
public:

    void solve(vector<int>& nums, set<vector<int>>& ans, vector<int>& temp, int i){
        if(i == nums.size()){
            if(temp.size()>=2) ans.insert(temp);
            return;
        }
        

        if(temp.size() == 0 || temp[temp.size()-1] <= nums[i]){
            temp.push_back(nums[i]);
            solve(nums,ans,temp,i+1);
            temp.pop_back();
        }

        solve(nums,ans,temp,i+1);
        
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int>temp;
        solve(nums, ans, temp,0);
        vector<vector<int>> res;
        for(auto s : ans){
            res.push_back(s);
        }
        return res;
    }
};