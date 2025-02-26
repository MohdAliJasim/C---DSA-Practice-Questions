class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for(int i = 0 ;i < nums.size();i++){
            int j = i+1;
            j = j%n;
            while(j  != i){
                if(nums[i] < nums[j]){
                    res.push_back(nums[j]);
                    break;
                }
                j++;
                j = j%n;
            }
            if(j == i) res.push_back(-1);
        }
        return res;
    }
};