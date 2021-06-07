# detail: https://atcoder.jp/contests/abc199/submissions/23267724
def outstr(str,pos):
  for i in range(pos,len(str)):
    print(str[i], end='')
  for i in range(pos):
    print(str[i], end='')
  print()

n=int(input())
s=list(input())
q=int(input())
start=0
for i in range(q):
  t,a,b=map(int,input().split())
  if t==2:
    start+=n
    start%=2*n
    continue
    
  a-=1
  b-=1
  idxa=(start+a)%(2*n)
  idxb=(start+b)%(2*n)
  # print(idxa,idxb)
  s[idxa],s[idxb]=s[idxb],s[idxa]
  # outstr(s,start)
  
outstr(s,start)