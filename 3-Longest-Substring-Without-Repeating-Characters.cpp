class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int r = 0 ;
        int l = 0 ;
        int ans = 0;
        set<char> st;
        while(r < s.size()){
            while(st.find(s[r])  != st.end()){
                st.erase(s[l]);
                l++;
            }


            st.insert(s[r]);

            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
    }
};