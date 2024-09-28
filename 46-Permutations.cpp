class Solution {
public:
    void f(vector<int>& nums, vector<vector<int>>& ans , vector<int> &ds, vector<int>&map, int index){
        if(index == nums.size()){
            ans.push_back(ds);
            return;
        }
        for(int i = 0 ; i < nums.size();i++){
            if(map[i] == 1){
                map[i] = 0;
                ds.push_back(nums[i]);
                f(nums, ans,ds , map ,index+1);
                map[i] =1;
                ds.pop_back();
                
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        vector<int> map(nums.size(),1);
        f(nums, ans, ds ,map,0);
        return ans;
    }
};