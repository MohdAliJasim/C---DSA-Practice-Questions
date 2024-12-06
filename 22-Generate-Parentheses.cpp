class Solution {
public:

    void solve(int open , int close, string op, vector<string>&ans){
        if(open == 0 && close == 0){
            ans.push_back(op);
            return;
        }

        if(op == \\){
            solve(open-1, close, \(\,ans);
        }
        else if(open == 0){
            op += ')';
            solve(open, close-1,op,ans);
        }
        else if(open == close){
            op += '(';
            solve(open-1,close ,op,ans);
        }
        else if(close == 1 && open > 0){
            op += '(';
            solve(open,close-1,op,ans);
        }
        else{
            string op1 = op;
            string op2 = op;
            op1 += '(';
            op2 += ')';
            solve(open-1,close,op1,ans);
            solve(open  , close-1,op2,ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(n , n, \\, ans);
        return ans;
    }
};