// detail: https://atcoder.jp/contests/abc205/submissions/23492201
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  int n;
  cin>>n;
  vector<int> vec(n);
  for(int i=0;i<n;i++){
    cin>>vec[i];
  }
  
  sort(vec.begin(),vec.end());
  bool answer = true;
  
  for(int i = 0; i < n; i++){
  if(!(vec[i] == i+1)){
    answer = false;  
    break;
  }
  }
  
  if(answer)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
 
  return 0;
}

