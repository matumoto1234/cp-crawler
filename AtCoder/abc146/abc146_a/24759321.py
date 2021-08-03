# detail: https://atcoder.jp/contests/abc146/submissions/24759321
weeks=["SUN","MON","TUE","WED","THU","FRI","SAT"]
# weeks=weeks[::-1]
s=input()
idx=0
for i in range(len(weeks)):
  if s==weeks[i]:
    idx=i
    break
    
print(7-idx)