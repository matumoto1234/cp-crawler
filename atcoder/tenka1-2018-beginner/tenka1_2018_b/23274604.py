# detail: https://atcoder.jp/contests/tenka1-2018-beginner/submissions/23274604
a,b,k=map(int,input().split())
turn=0
while k:
  if turn%2==0:
    b+=a//2
    a//=2
  else:
    a+=b//2
    b//=2
  turn+=1
  k-=1
  
print(a,b)