// detail: https://atcoder.jp/contests/abc270/submissions/43673909
#include <bits/stdc++.h>
using namespace std;

int main() {
  int x,y,z;
  cin>>x>>y>>z;
  
  if(x < z and z < y and y < 0 or
     z < x and x < y and y < 0 or
     0 < y and y < z and z < x or
     0 < y and y < x and x < z
    ) {
    cout<<-1<<endl;
    return 0;
  }

  if(0 < z and z < y and y < x or
     z < 0 and 0 < y and y < x or
     x < 0 and y < z and z < 0 or
     x < y and y < 0 and 0 < z
    ) {
    cout << abs(z) + abs(z-x) << endl;
    return 0;
  }
  
  cout << abs(x) << endl;
}