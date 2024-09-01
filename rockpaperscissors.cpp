#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    string str; cin >> str;
    string lowerStr = "";
    for(int i = 0; i < str.size();i++){
        char c = (char) tolower(str[i]);
        lowerStr += c;
    }
    if(lowerStr == "scissors"){
        cout << "rock";
    }
    else if(lowerStr == "paper"){
        cout << "scissors";
    }
    else{
        cout << "paper";
    }

    return 0;
}