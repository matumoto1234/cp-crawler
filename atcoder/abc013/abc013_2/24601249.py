# detail: https://atcoder.jp/contests/abc013/submissions/24601249
a=int(input())
b=int(input())

def mod(x):
  return (x%10+10)%10

ia=a
da=a
ans=0
while 1:
  if mod(ia)==mod(b) or mod(da)==mod(b):
    break
  ia+=1
  da-=1
  ans+=1
  
print(ans)