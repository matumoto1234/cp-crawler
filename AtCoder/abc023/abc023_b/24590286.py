# detail: https://atcoder.jp/contests/abc023/submissions/24590286
n=int(input())
s=input()
t="b"
cnt=0
while len(t)<len(s):
  if t==s:
    print(cnt)
    exit()
    
  t="a"+t+"c"
  cnt+=1
  if t==s:
    print(cnt)
    exit()
    
  t="c"+t+"a"
  cnt+=1
  if t==s:
    print(cnt)
    exit()
    
  t="b"+t+"b"
  cnt+=1
  if t==s:
    print(cnt)
    exit()
    
print(-1)