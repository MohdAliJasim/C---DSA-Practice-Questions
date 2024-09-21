#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void f(vector<int>&ds, int arr [], int n,int index){
  if(index >= n){
    if(ds.size() == 0){
      cout << "{}" << endl;
      return;
    }
    for(auto a : ds) cout << a;
    cout << endl;
    return;
  }
  //make the call for taking
  ds.push_back(arr[index]);
  f(ds , arr, n, index+1);
  ds.pop_back();
  
  //make the call for not taking
  f(ds, arr , n, index+1);
}



int main(){
  int arr[]= {3,1,2};
  vector<int>ds;
  f(ds,arr,3,0);
  return 0;
}