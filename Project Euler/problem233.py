# Solved using Schinzel's Theorem

MAX_P = 10**7
N = 10**11

isPrime = [False,False] + [True]*(MAX_P-2)
primes = []

for i in range(MAX_P):
    if not isPrime[i]: continue
    primes.append(i)
    for j in range(i*i, MAX_P, i): isPrime[j] = False

def count2(p, acc):
  t = acc
  bnd = N // acc
  while primes[p] <= bnd:
    if p == 0 or primes[p] % 4 == 3:
      b = acc * primes[p]
      while b <= N:
        t += count2(p+1, b)
        b *= primes[p]
    p += 1
  return t

def count1(f, i, ps, acc):
  if i == len(f):
    return count2(0, acc)
  t = 0
  q = (f[i] - 1) // 2
  p = 0
  bnd = (N / acc)**(1/q)
  while primes[p] <= bnd:
    if primes[p] % 4 == 1 and p not in ps:
      t += count1(f, i+1, ps+[p], acc * primes[p]**q)
    p += 1
  return t

facts = [[7,5,3], [15,7], [21,5]]
ans = sum(count1(f, 0, [], 1) for f in facts)
print(ans)
