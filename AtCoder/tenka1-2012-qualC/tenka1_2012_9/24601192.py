# detail: https://atcoder.jp/contests/tenka1-2012-qualC/submissions/24601192
def is_prime(x):
  if x<=1:
    return False
  i=2
  while i*i<=x:
    if x%i==0:
      return False
    i+=1
  return True

n=int(input())
ans=0
for i in range(2,n):
  if is_prime(i):
    ans+=1
    
print(ans)