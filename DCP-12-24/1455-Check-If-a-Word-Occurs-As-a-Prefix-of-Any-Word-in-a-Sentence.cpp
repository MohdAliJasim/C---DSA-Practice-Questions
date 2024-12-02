class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        vector<string> match;
        string str ="";
        for(int i = 0 ;i < sentence.size();i++){
            if(sentence[i] == ' ' ){
                match.push_back(str);
                str = "";
            }
            else if(i == sentence.size()-1){
                str += sentence[i];
                match.push_back(str);
            }
            else{
                str += sentence[i];
            }
        } 
        for(string s: match) cout << s << " ";
        for(int i = 0 ;i < match.size();i++){
            if(match[i].size() < searchWord.size()) continue;
            bool flag = true;
            for(int j = 0 ; j < searchWord.size();j++){
                if(searchWord[j] != match[i][j]){
                    flag = false;
                    break;
                } 
            }
            if(flag){
                return i+1;
            }
            
        }
        return -1;
    }
};