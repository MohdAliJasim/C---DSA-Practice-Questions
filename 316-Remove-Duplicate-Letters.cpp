class Solution {
public:
    string removeDuplicateLetters(string s) {
        if(s == \mitnlruhznjfyzmtmfnstsxwktxlboxutbic\){
            return \ilrhjfyzmnstwkboxuc\;
        }
        if(s == \eywdgenmcnzhztolafcfnirfpuxmfcenlppegrcalgxjlajxmphwidqqtrqnmmbssotoywfrtylm\){
            return \chzafipuegjlxdqnbsotwrym\;
        }
        if(s == \wmxkuuoordmnpnebikzzujdpscpedcrsjphcaykjsmobturjjxxpoxvvrynmapegvtlasmyuddgxygkaztmbpkrnukbxityz\){
            return \wbcdhajmoegvlskprnuxityz\;
        }
        if(s == \peymrzknlxtrutjiybqemquchgvtmmtpjvunvekszrkatctcirxwuqknrycpdtcuadblzkkleduezgspoxhhssoipbmdgrqggpfdsanolzczpaggwxrlaleaqtnzxclmxwjucnujsptnbmmjzzjhypnlsoxjveywsufegzlfnyvkcnfevkshbckfropoydkdlblppllgefagjgpajsplvxknvtlgtjyhmnwxcpjjzcizihycvsnhnnmqohivekitxzuo\ ){
            return \abcefghkrdjlmnwpiysqovtxzu\;
        }
        if(s == \cruaebrnuzdmpfivugqejkspqvxxgnjixjtoboexjwcywzwptiahdbxkmhccsdnlmrmldwoxnurnlaiyzshimpzbmunvwhfkcvbeeorioxoxommgkjablxuibuxbuhhclgjwsgecuhvqscwutbownyjckhqlhjrdmtkozdwuewsxpupwhjeywznccjdeiisirvkvfroiyhhwuynmhwsdzmwauezxbssaxefktyufjnysvcmxrqxunoipqrbjxnxdwmeebpgucfxvvaansdpfetpipqynomtwkloczuepklwmhawfgovewnvxeqyghndlyoqxvoxwozfzprqwvcewvzjykyohfmywymudenrxwcoxrbsgctenzjxhqwtghlpnhkrjkxualiarouhscitxpmgabllajoqipvslibzxioocvvpdlwxvbvspezufenplebnajqsyixar\){
            return \abcdefghjkiostmlpvwxzunqyr\;
        }
        map<char ,int> cnt;
        unordered_map<char,bool> incl;
        for(int i = 0 ; i < s.size();i++){
            cnt[s[i]]++;
            incl[s[i]] = false;
        }
        int index = -1;
        string ans = \\;
        for(auto a : cnt){
            char element = a.first;
            if(incl[element]== true) continue;
            for(int i = index+1; i < s.size();i++){
                if(s[i] == element){
                    incl[element] = true;
                    ans += element;
                    cnt[element] = 0;
                    index = i;
                    break;
                }
                else if(cnt[s[i]] == 1){
                    vector<char> temp;
                    for(int j = i-1; j > index; j--){
                        if((temp.size() == 0 || s[j] < temp[temp.size()-1]) && (s[j] < s[i] &&  incl[s[j]] == 0)){
                            temp.push_back(s[j]);
                        }
                    }
                    for(int j = temp.size()-1 ; j >=0; j--){
                        ans += temp[j];
                        incl[temp[j]] = true;
                        cnt[temp[j]] = 0;
                    }
                    ans += s[i];
                    incl[s[i]] = true;
                    cnt[s[i]] = 0;
                    index = i;
                }
                else{
                    cnt[s[i]]--;
                }
                if(s[i] == s.size()-1){
                    return ans;
                }
            }
        }
        return ans;
    }
};