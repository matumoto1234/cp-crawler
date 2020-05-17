// detail: https://atcoder.jp/contests/abc168/submissions/13344535
#include <bits/stdc++.h>
#define loop(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using ld = long double;

int main(void){
    ld a, b, h, m;
    ld rad;
    ld ans;

    cin >> a >> b >> h >> m;

    h=h*(ld)30.0+m*(ld)0.5;
    m=m*(ld)6.0;
    rad=h-m;
    rad=rad*(ld)3.1415926535897932384626/(ld)180.0;

    if(rad<0)rad*=-1.0;
    ans=a*a+b*b+((ld)-2.0*a*b*cos(rad));
    //cout<<ans<<endl;
    printf("%.30Lf\n",sqrtl(ans));
    //cout<<sqrtl(ans)<<endl;
    return 0;
}