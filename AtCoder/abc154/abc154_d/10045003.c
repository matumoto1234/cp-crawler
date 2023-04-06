// detail: https://atcoder.jp/contests/abc154/submissions/10045003
#include<stdio.h>
#include<stdlib.h>
double kitai(int n)
{
  double sum=0.0;
  for(int i=1;i<=n;i++){
    sum+=(double)i;
  }
  sum/=(double)n;
  return sum;
}
int main(void)
{
  int n,k;
  int p[200000];
  int rui[200001];
  scanf("%d %d",&n,&k);
  rui[0]=0;
  for(int i=0;i<n;i++){
    scanf("%d",&p[i]);
    rui[i+1]+=p[i]+rui[i];
  }
  int max,maxi,tmp;
  max=maxi=0;
  for(int i=0;i<n+1-k;i++){
    tmp=rui[i+k]-rui[i];
    if(max<tmp){
      max=tmp;
      maxi=i;
    }
  }
  double ans=0.0;
  for(int i=maxi;i<maxi+k;i++){
    ans+=kitai(p[i]);
  }
  printf("%lf\n",ans);
  return 0;
}