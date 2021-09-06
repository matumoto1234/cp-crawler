// detail: https://atcoder.jp/contests/typical90/submissions/25648405
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdint>
using namespace std;

int main(void){
  int classn;
  cin>>classn;
  int clas[classn];
  for(int i = 0 ; i < classn ; i++){
    cin>>clas[i];
  }
  int studentn;
  cin>>studentn;
  sort(clas,clas+classn);
  for(int i = 0; i < studentn; i++ ){
    int student;
    cin>>student;
    int j = 0;
    int k = classn-1;
    bool found = false;
    while(1){
      int center = (j + k) / 2;
      if(student > clas[center]){
        j = center + 1;
      }else if(student < clas[center]){
        k = center - 1;
      }else{
        found = true;
        break;
      }
      if(k - j <= 1) break;
    }
    if ( found ) {
      cout << 0 << endl;
      continue;
    }
    int upper = INT32_MAX, lower = INT32_MAX;
    if(0 <= k && k < classn) upper = abs(clas[k] - student);
    if(0 <= j && j < classn) lower = abs(clas[j] - student);
    // int upper = abs(clas[k] - student);
    // int lower = abs(student - clas[j]);
    if (j-1>=0) lower = min(lower, abs(student - clas[j-1]));
    if (j+1<classn) lower = min(lower, abs(student - clas[j+1]));
    if (k-1>=0) upper = min(upper, abs(student - clas[k-1]));
    if (k+1<classn) upper = min(upper, abs(student - clas[k+1]));
    cout<<min(lower, upper)<<endl;
  }
  return 0;
}