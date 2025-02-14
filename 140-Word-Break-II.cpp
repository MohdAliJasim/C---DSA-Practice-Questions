class Solution {
public:
    unordered_map<string, int> map;


    void solve(string &s, vector<string>& temp, vector<string> &res, int index){
        if(index == s.size()){
            string temp2 = \\;
            for(int i =0  ;i < temp.size();i++){
                temp2 += temp[i];
                if(i < temp.size()-1) temp2 += ' ';
            }

            res.push_back(temp2);
            return;
        }
        string p = \\;
        for(int i = index; i < s.size();i++){
            p+= s[i];
            if(map[p]){
                temp.push_back(p);
                solve(s , temp, res, i+1);
                temp.pop_back();
            }
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
         for(string str : wordDict) map[str]++;
         vector<string> res;
         vector<string> temp;
         solve(s ,temp, res , 0);
         return res;
    }
};