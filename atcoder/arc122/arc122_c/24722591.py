# detail: https://atcoder.jp/contests/arc122/submissions/24722591
vs=[0 for _ in range(1000000)]
fibs=[0 for _ in range(1000000)]
fibs[0]=fibs[1]=1
for i in range(2,len(fibs)):
  fibs[i]=fibs[i-1]+fibs[i-2]
  if(fibs[i]>=1000000):
    break
  
for j in range(1,1000000):
  for i in range(1,len(fibs)):
    if fibs[i]*j>=1000000:
      break
    vs[fibs[i]*j]=1
  
for i in range(1,len(vs)):
  if vs[i]==0:
    print(i)
    exit()