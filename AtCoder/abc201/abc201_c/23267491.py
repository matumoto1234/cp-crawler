# detail: https://atcoder.jp/contests/abc201/submissions/23267491
s=input()
def is_valid(a,b,c,d):
  vs=[a,b,c,d]
  for i in range(4):
    if s[vs[i]]=='x':
      return False

  for i in range(len(s)):
    if s[i]=='o':
      found=False
      for j in range(4):
        if i==vs[j]:
          found=True
          
      if found==False:
        return False
      
  return True


ans=0
for i in range(10):
  for j in range(10):
    for k in range(10):
      for l in range(10):
        if is_valid(i,j,k,l):
          ans+=1
          
print(ans)