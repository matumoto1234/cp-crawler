// detail: https://atcoder.jp/contests/abc194/submissions/20755182
using ll = long long;
using PL = pair<ll, ll>;
using P = pair<int, int>;
const ll INF64 = INT64_MAX / 2;
const int INF32 = INT32_MAX / 2;
const char newl = '\n';

int main() {
  int a,b;
  cin>>a>>b;
  int sum=a+b;
  if(sum>=15&&b>=8){
    cout<<1<<endl;
  }else if(sum>=10&&b>=3){
    cout<<2<<endl;
  }else if(sum>=3){
    cout<<3<<endl;
  }else{
    cout<<4<<endl;
  }
}