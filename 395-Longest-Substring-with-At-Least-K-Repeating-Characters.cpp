class Solution {
public:
    int longestSubstring(string s, int k) {
        int maxi =0;

        for(int i=0 ;i < s.size();i++){
            unordered_map<char,int> map;
            for(int j = i;j < s.size();j++){
                map[s[j]]++;
                bool flag = true;
                for(auto m : map){
                    if(m.second < k){
                        flag= false;
                        break;
                    }
                }
                if(flag) maxi = max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};