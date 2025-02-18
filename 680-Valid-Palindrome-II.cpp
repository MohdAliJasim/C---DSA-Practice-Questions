class Solution {
public:

    bool valid(string& s){
          int i = 0 ;
         int j = s.size()-1;
        bool flag = true;
         while(i < j){
            if(s[i] != s[j] && flag){
                flag = false;
                if(s[i] == s[j-1]) {
                    j--;
                    j--;
                    i++;
                    continue;}
                if(s[i+1] == s[j]){
                    j--;
                    i++;
                    i++;
                continue;
            }
                return false;
                } 
            else if(s[i] != s[j] && !flag){
                return false;
            }
            i++;
            j--;
         }
         return true;
    }

    bool valid2(string &s){
          int i = 0 ;
         int j = s.size()-1;
        bool flag = true;
         while(i < j){
            if(s[i] != s[j] && flag){
                flag = false;
                if(s[i+1] == s[j]){
                    j--;
                    i++;
                    i++;
                continue;
                } 
                if(s[i] == s[j-1]) {
                    j--;
                    j--;
                    i++;
                    continue;}
                return false;
            }
            else if(s[i] != s[j] && !flag){
                return false;
            }
            i++;
            j--;
         }
         return true;
    }

    bool validPalindrome(string s) {
         return valid(s) || valid2(s);
    }
};