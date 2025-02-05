class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
       unordered_map<char,int> map1;
       unordered_map<char, int> map2;
        int count = 0;
        for(int i= 0 ;i < s1.size();i++){
            if(s1[i] != s2[i]) count++;
            map1[s1[i]]++;
            map2[s2[i]]++;
        }
        if(map1 != map2) return false;
        if(count <= 2) return true;
    
        return false;
    }
};