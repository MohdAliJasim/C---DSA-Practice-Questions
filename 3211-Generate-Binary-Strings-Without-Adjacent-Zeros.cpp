class Solution {
public:

    void solve(int n , vector<string>& ans , string& temp){
        if(n == 0){
            ans.push_back(temp);
            return;
        }
       
            if(temp.size()==0){
                temp.push_back('0');
                solve(n-1,ans,temp);
                temp.pop_back();
                temp.push_back('1');
                solve(n-1,ans,temp);
                temp.pop_back();
            }
            else{
                if(temp[temp.size()-1] != '0'){
                     temp.push_back('0');
                    solve(n-1,ans,temp);
                    temp.pop_back();
                    temp.push_back('1');
                    solve(n-1,ans,temp);
                    temp.pop_back();
                }
                else{
                    temp.push_back('1');
                    solve(n-1,ans,temp);
                    temp.pop_back();
                }
            }
        
    }

    vector<string> validStrings(int n) {
        vector<string> ans;
        string temp = "";
        solve(n ,ans , temp);
        return ans;
    }
};