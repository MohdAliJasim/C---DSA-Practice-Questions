#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(){
    int n; cin >> n;
    int count =0 ;
    for(int i = 1; i <= n ;i++){
        int sum = 0;
        int j = i;
        while(j){
            if(j&1)
                sum += 2;
            else
                sum += 1;
            j >>=1;
        }
        if(sum%2 == 1)
            count++;
    }
    cout << count;
    return 0;
}
