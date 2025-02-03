class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,long long>map;

        for(int i =0 ;i < t.size();i++){
            map[t[i]]++;
        }
        string res = \\;
        long long count = map.size();
        int r = 0, l = 0 , len = INT_MAX, start = 0, end = INT_MAX;
        while(r<s.size()){

            while( r < s.size() && count != 0){
                if(map.find(s[r]) != map.end()){
                    map[s[r]]--;
                    if(map[s[r]] == 0) count--;
                }
                r++;
            }

            while(count == 0){
                if(end-start > r-l){
                    end = r;
                    start = l;
                } 

                if(map.find(s[l]) != map.end()){
                    map[s[l]]++;
                    if(map[s[l]] == 1) count++;

                }
                l++;
            }

            
        }
        return end-start==INT_MAX?\\:s.substr(start,end-start);
    }
};