# detail: https://atcoder.jp/contests/tenka1-2015-qualb/submissions/24601149
a=[0 for _ in range(20)]
a[0],a[1],a[2]=100,100,200
for i in range(3,20):
  a[i]=a[i-1]+a[i-2]+a[i-3]
  
print(a[19])