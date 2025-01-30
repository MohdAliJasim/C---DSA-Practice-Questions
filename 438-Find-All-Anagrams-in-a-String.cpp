class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char , int> map;
        int count = 0;
        vector<int> ans;

        int n = s.size();
        int m = p.size();

        for(int i= 0 ;i < m;i++){
            map[p[i]]++;
        }
        count = map.size();
        int l = 0;
        int r = -1;
        while(r < n){
                r++;
            if(r < m){
                map[s[r]]--;
                if(map[s[r]] == 0) count--;
            }
            else{
                if(count == 0) ans.push_back(l);
                
                map[s[l]]++;
                if(map[s[l]] == 1) count++;
                map[s[r]]--;

                if(map[s[r]] == 0) count--;
                
                l++;
            }
        }
        return ans;
    }
};