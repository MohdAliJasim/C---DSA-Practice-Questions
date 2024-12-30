class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int r = 0 ; 
        int l = 0 ;
        int maxLen = 0;
        unordered_map<int ,int> map;
        while(r < fruits.size()){
            map[fruits[r]]++;
            r++;
            if(map.size() <= 2){
                maxLen = max(maxLen , r-l);
            }
            else{
                map[fruits[l]]--;
                if(map[fruits[l]] == 0){
                    map.erase(fruits[l]);
                }
                l++;
            }
        }
        return maxLen;
    }
};