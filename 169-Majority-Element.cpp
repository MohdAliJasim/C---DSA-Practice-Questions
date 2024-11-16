class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int i = 0;i < nums.size();i++){
            map[nums[i]]++;
        }
        int maxi = 0;
        int maxiInd = 0;
        for(auto a : map){
          if(maxi < a.second){
            maxi = a.second;
            maxiInd = a.first;
          }
        }
        return maxiInd;
    }
};