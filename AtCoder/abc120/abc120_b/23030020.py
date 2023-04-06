# detail: https://atcoder.jp/contests/abc120/submissions/23030020
a, b, k = map(int,input().split())

divs = []
for i in range(1, 1000):
  if a % i == 0 and b % i == 0:
    divs.append(i)
    
list.sort(divs, Reverse=True)
print(divs[k-1])