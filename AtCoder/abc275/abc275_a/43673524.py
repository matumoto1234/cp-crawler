# detail: https://atcoder.jp/contests/abc275/submissions/43673524
n = int(input())
a = list(map(int,input().split()))

max_i = 0
max_a = -1
for i in range(len(a)):
  if max_a < a[i]:
    max_a = a[i]
    max_i = i
    
print(max_i+1)
  