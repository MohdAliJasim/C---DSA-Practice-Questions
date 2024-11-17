class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        vector<int> ans;
        k = k%nums.size();
        if(k == 0) return;
        for(int i =0;i< nums.size();i++){
           
            ans.push_back(nums[(nums.size()+i-k)%nums.size()]);
        }
        nums.clear();
        nums.insert(nums.begin(),ans.begin(),ans.end());
    }
};