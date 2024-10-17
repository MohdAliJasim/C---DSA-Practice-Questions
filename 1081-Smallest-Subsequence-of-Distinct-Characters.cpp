class Solution {
public:
    string smallestSubsequence(string s) {
        map<char ,int> cnt;
        unordered_map<char,bool> incl;
        for(int i = 0 ; i < s.size();i++){
            cnt[s[i]]++;
            incl[s[i]] = false;
        }
        stack<char> st;
        for(int i = 0 ;i < s.size();i++){
            if(incl[s[i]] == true){
                cnt[s[i]]--;
                continue;
            }
            if(st.empty()){
                st.push(s[i]);
                incl[s[i]] = true;
                cnt[s[i]]--;
            }
            else{
                
                while(!st.empty() && s[i] < st.top() && cnt[st.top()] > 0){
                    char top = st.top();
                    incl[top] = false;
                    st.pop();
                }
                st.push(s[i]);
                incl[s[i]] = true;
                cnt[s[i]]--;
            }
        }
        string ans;
        int size = st.size();
        for(int i = 0; i < size ;i++){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};