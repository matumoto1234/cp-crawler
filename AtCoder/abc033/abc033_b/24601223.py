# detail: https://atcoder.jp/contests/abc033/submissions/24601223
n=int(input())

sum=0
ss=[]
pp=[]

for i in range(n):
  s,p=input().split()
  p=int(p)
  sum+=p
  ss.append(s)
  pp.append(p)
  
for i in range(n):
  s,p=ss[i],pp[i]
  if p*2>sum:
    print(s)
    exit()
print("atcoder")