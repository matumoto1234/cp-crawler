// detail: https://atcoder.jp/contests/abc167/submissions/13084372
#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m,x,min=INT_MAX,tempSum;
    cin>>n>>m>>x;
    vector<int> c(n),num(n);
    vector<vector<int>> a(n,vector<int>(m));

    for(int i=0;i<n;i++){
        cin>>c[i];
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++)num[i]=i;

    
    do{
        tempSum=0;
        vector<int> list(m,0);
        for(int ii=0;ii<n;ii++){
            tempSum+=c[num[ii]];
            for(int i=0;i<m;i++){
                list[i]+=a[num[ii]][i];
              	int flg=0;
        		for(int j=0;j<m;j++){
            		if(list[j]<x){
                		flg=1;
            		}
        		}
              	if(flg==0){
            		if(min>tempSum){
               	 		min=tempSum;
            		}
        		}
            }
        }
    }while(next_permutation(num.begin(),num.end()));
    if(min==INT_MAX){
      cout<<-1<<endl;
    }else{
      cout<<min<<endl;
    }
    return 0;
}