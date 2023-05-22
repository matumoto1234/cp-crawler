# detail: https://atcoder.jp/contests/abc283/submissions/37983944
n = int(input())
a_list = list(map(int, input().split()))
q = int(input())
for _ in range(q):
  query = input()
  if query[0] == '1':
    _, k, x = map(int, query.split())
    a_list[k-1] = x
  if query[0] == '2':
    _, k = map(int, query.split())
    print(a_list[k-1])