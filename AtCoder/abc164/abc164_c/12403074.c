// detail: https://atcoder.jp/contests/abc164/submissions/12403074
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;

int main(int argc,char* argv[]){
    int n,ans=1;
    vector<string> data;
    string str;

    cin>>n;

    for(int i=0;i<n;i++){
        cin>>str;
        data.push_back(str);
    }
    sort(data.begin(),data.end());
    for(int i=1;i<n;i++){
        if(data[i]!=data[i-1]){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}