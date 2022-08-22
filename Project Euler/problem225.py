def tri_check(n):
  a,b,c=1,1,1
  seen=set()
  while (a,b,c) not in seen:
    if c % n == 0: return False
    seen.add((a,b,c))
    a,b,c=b,c,(a+b+c)%n
  return True

k = 0
for i in range(1,10000,2):
  if tri_check(i):
    k += 1
    if k == 124:
        print(i)
        break
