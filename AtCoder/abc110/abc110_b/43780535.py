# detail: https://atcoder.jp/contests/abc110/submissions/43780535
n,m,x,y = map(int,input().split())
xs = list(map(int,input().split()))
ys = list(map(int,input().split()))

for z in range(x+1, y+1):
  valid = True

  for xx in xs:
    if xx >= z:
      valid = False
      break
  
  for yy in ys:
    if yy < z:
      valid = False
      break
      
  if valid:
    print("No War")
    exit()
    
print("War")