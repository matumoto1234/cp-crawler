// detail: https://atcoder.jp/contests/abc144/submissions/8180650
#include<stdio.h>
#include<math.h>
typedef double d;
d to_deg(d r){return r*180.0/(atan(1.0)*4.0);}
int main(void)
{
    int a,b,x;
    double h,v,rad;

    scanf("%d %d %d",&a,&b,&x);
    v=(d)a*(d)a*(d)b;
    if(v/2.0>x){
        h=(2.0*(d)x)/((d)a*(d)b);
        rad=atan2(h,(d)b);
        printf("%lf\n",90.0-to_deg(rad));
    }
    else{
        h=((2.0*(v-(d)x))/((d)a*(d)a));
        rad=atan2(h,(d)a);
        printf("%lf\n",to_deg(rad));
    }
    return 0;
}