// detail: https://atcoder.jp/contests/abc165/submissions/12649691
#include<bits/stdc++.h>
using namespace std;

typedef struct{
    int d;
    int i;
}ddd;
void recursive_comb(int *indexes, int s, int rest, std::function<void(int *)> f) {
  if (rest == 0) {
    f(indexes);
  } else {
    if (s < 0) return;
    recursive_comb(indexes, s - 1, rest, f);
    indexes[rest - 1] = s;
    recursive_comb(indexes, s - 1, rest - 1, f);
  }
}

// nCkの組み合わせに対して処理を実行する
void foreach_comb(int n, int k, std::function<void(int *)> f) {
  int indexes[k];
  recursive_comb(indexes, n - 1, k, f);
}



int main(){
    int n,m,q;
    int maax=0;
    int temp;

    cin>>n>>m>>q;
    vector<int> ans(10,1);
    vector<int> a(n),b(n),c(n);
    vector<int> d(n);

    for(int i=0;i<q;i++){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
    }
  int sum=0;

    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 1; bit <= (1<<n); ++bit) {
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                S.push_back(i);
            }
        }
      for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
          if(S[a[i]]-S[a[j]]==c[i]){
            temp+=d[i];
          }
        }
      }
      if(maax<temp){
        maax=temp;
      }

        /*cout << bit << ": {";
        for (int i = 0; i < (int)S.size(); ++i) {
            cout << S[i] << " ";
        }
        cout << "}" << endl;*/
    }
  cout<<maax<<endl;
  return 0;
}