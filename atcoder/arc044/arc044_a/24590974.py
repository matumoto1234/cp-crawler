# detail: https://atcoder.jp/contests/arc044/submissions/24590974
import math
n=int(input())

if n==1:
  print("Not Prime")
  exit()

def is_prime(x):
  if x<=1:
    return False
  for i in range(2, int(math.sqrt(x))+10):
    if i>=x:
      break
    if x%i==0:
      return False
  return True

nn=n
sum=0
while nn>0:
  sum+=nn%10
  nn//=10
  
# print(sum, is_prime(n), n%10%2!=0, n%10!=5, sum%3!=0)

if is_prime(n) or (n%10%2!=0 and n%10!=5 and sum%3!=0):
  print("Prime")
else:
  print("Not Prime")