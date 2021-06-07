# detail: https://atcoder.jp/contests/cf16-final/submissions/23273126
def num2alpha(num):
    if num<=26:
        return chr(64+num)
    elif num%26==0:
        return num2alpha(num//26-1)+chr(90)
    else:
        return num2alpha(num//26)+chr(64+num%26)
      
h,w=map(int,input().split())
s=[list(input().split()) for _ in range(h)]

for i in range(h):
  for j in range(w):
    if s[i][j]=='snuke':
      print(num2alpha(j+1),i+1, sep='')