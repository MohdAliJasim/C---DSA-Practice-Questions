#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; 
  vector<int> arr;
  int num;
  while(cin >> num) arr.push_back(num);
  for(int i = 0 ;i < arr.size() ;i++){
    for(int j = 0; j < arr.size()-i-1;j++){
      if(arr[j] > arr[j+1]) swap(arr[j], arr[j+1]);
    }
  }
  for(int a : arr) cout << a << " ";

}