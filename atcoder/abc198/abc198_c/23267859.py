# detail: https://atcoder.jp/contests/abc198/submissions/23267859
r,x,y=map(int,input().split())

if r*r>x*x+y*y:
  print(2)
  exit()
elif r*r==x*x+y*y:
  print(1)
  exit()

valid=2*10**18
invalid=0
while abs(valid-invalid)>1:
  mid=(valid+invalid)//2
  if x*x+y*y<=mid*mid*r*r:
    valid=mid
  else:
    invalid=mid
    
print(valid)