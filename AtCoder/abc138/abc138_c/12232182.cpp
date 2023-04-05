// detail: https://atcoder.jp/contests/abc138/submissions/12232182
#include<iostream>
#include<vector>
#include<stdlib.h>
#include<algorithm>
//#include"cxx-prettyprint/prettyprint.hpp"
#include<math.h>
using namespace std;



int main(int argc,char *argv[]){
    
    int n;
    vector<double> v(50);
    double ans=0.0;

    cin>>n;
    for(int i=0;i<n;i++) cin>>v[i];
    sort(v.begin(),v.end(),greater<double>());
    
    for(int i=0;i<n;i++){
        ans+=v[i]/pow(2.0,(double)i+1.0);
    }
    cout<<ans<<endl;

    return 0;
}