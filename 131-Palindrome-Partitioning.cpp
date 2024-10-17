class Solution {
public:
    bool palindrome(string s){
        int st = 0;
        int e = s.length()-1;
        while(st < e){
            if(s[st] == s[e]){
                st++;
                e--;
            }
            else{
                return false;
            }
        }
        return true;
    }
    void f(string s , vector<vector<string>> &ans, vector<string> &ds, int index , int n){
        if(index == n){
            ans.push_back(ds);
            
        }
        string str = \\;
        for(int i = index ; i < n; i++){
            str += s[i];
            if(palindrome(str)){
                ds.push_back(str);
                f(s , ans, ds ,i+1,n);
                ds.pop_back();
            }
           
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        f(s, ans , ds, 0 , s.length());
        return ans;
    }
};