// detail: https://atcoder.jp/contests/abc126/submissions/8428368
#include<iostream>
using namespace std;
int main(void)
{
  int s;
  int keta[6];
  int flg1,flg2,flg3;
  
  flg1=flg2=flg3=0;
  cin>>s;
  for(int i=1;i<=4;i++){
    keta[i-1]=s%10;
    s/=10;
  }
  keta[4]=keta[1]*10+keta[0];
  keta[5]=keta[3]*10+keta[2];
  //printf("%d %d\n",keta[4],keta[5]);
  if(keta[4]>=1&&keta[4]<=12){
    if(keta[5]>=0&&keta[5]<=99){
      flg1=1;
    }
  }
  if(keta[4]>=00&&keta[4]<=99){
    if(keta[5]>=1&&keta[5]<=12){
      flg2=1;
    }
  }
  if(flg1==1&&flg2==1){
    cout<<"AMBIGUOUS"<<endl;
  }
  else if(flg2==1){
    cout<<"MMYY"<<endl;
  }
  else if(flg1==1){
    cout<<"YYMM"<<endl;
  }
  else{
    cout<<"NA"<<endl;
  }
  return 0;
}