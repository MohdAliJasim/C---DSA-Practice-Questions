class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> map;
        for(int a : nums) map[a]++;

        for(auto a : map){
            if(a.second > 1){
                return a.first;
            }
        }
        return 1;
    }
};