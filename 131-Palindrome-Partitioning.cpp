class Solution {
public:
    vector<vector<string>> ans;

    bool isPalindrome(string &s){
        for(int i = 0;i < s.size()/2;i++){
            if(s[i] != s[s.size()-1-i]){
                return false;
            }
        }
        return true;
    }

    void solve(string &s , vector<string>& temp, int index){
        if(index == s.size()){
            ans.push_back(temp);
            return;
        }
        string p;
        for(int i = index; i < s.size();i++){
            p.push_back(s[i]);
            if(isPalindrome(p)){
                temp.push_back(p);
                solve(s , temp, i+1);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(s , temp , 0);
        return ans;
    }
};