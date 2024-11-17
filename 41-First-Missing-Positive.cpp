class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
     //  sort(nums.begin(), nums.end());
        unordered_map<int,int> map;
        for(int i = 0;i < nums.size();i++){
            map[nums[i]]++;
        }
        for(int i =1 ;i < INT_MAX;i++){
            if(!map[i]){
                return i;
            }
        }
        return INT_MAX;
    }
};