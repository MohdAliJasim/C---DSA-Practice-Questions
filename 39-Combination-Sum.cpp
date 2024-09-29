class Solution {
public:
    void cs(int index , int target, vector<int> &arr , vector<vector<int>> &ans , vector<int> ds){
        if(index == arr.size()){
            if(target  == 0) ans.push_back(ds);
            return;
        }
        if(target >= arr[index]){
            ds.push_back(arr[index]);
            cs(index,target - arr[index], arr,ans , ds);
            ds.pop_back();
        }
        cs(index+1,target,arr,ans,ds);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        cs(0 , target , candidates, ans , ds);
        return ans;
    }
};