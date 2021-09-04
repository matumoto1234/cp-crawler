// detail: https://atcoder.jp/contests/typical90/submissions/25618799
#include<iostream>
#include<algorithm>
#include<cmath>
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
    int center = (j + k) / 2; 
    while(j < k){
      if(student > clas[center]){
        j = center;
      }else if(student < clas[center]){
        k = center;
      }else{
        break;
      }
      
    }
    int upper = abs(clas[k] - student);
    int lower = abs(student - clas[j]);
    cout<<min(lower,upper)<<endl;
    
  }
  return 0;
     

}


