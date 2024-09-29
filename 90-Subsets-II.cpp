class Solution {
public:
    void f(int index  , vector<int>&ds,vector<vector<int>>&ans, vector<int>&num){
         ans.push_back(ds);
        for(int i = index ; i < num.size();i++){
            if(i > index && num[i] == num[i-1]) continue;
            ds.push_back(num[i]);
            f(i+1, ds, ans, num);
            ds.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(),nums.end());
        f(0,ds,ans,nums);
        return ans;

    }
};