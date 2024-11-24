class Solution {
public:
    bool allOne(unordered_map<char , int>&map){
        bool ans = true;
        for(auto it : map){
            if(it.second>1) return false;
        }
        return true;
    }
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int > map;
        int l =0; 
        int r = 0;
            
      
        while(r!=s.size()){
           map[s[r]]++;
            if(allOne(map)){
                r++;
            }
            else{
                map[s[l]]--;
                r++;
                l++;
            }
        }
        return r-l;
    }
};