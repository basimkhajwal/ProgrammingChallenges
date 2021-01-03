from functools import lru_cache

@lru_cache(maxsize=2**20)
def solve(c, f, n0, n1, n2, p):
  # c = no of current card
  # f = 0: draw first, 1: draw second, 2: next player
  # n`i` = cards after with i remaining
  # p = previous cards remaining
  rem = n0 + n1 + n2
  tot = n1 + 2*n2 + p

  ans = 0
  if rem == 0:
    ans = 0 if c == 0 else 1
  elif f <= 1:
    if p: ans += p * solve(c, f+1, n0, n1, n2, p-1)
    if n1: ans += n1 * solve(c, f+1, n0+1, n1-1, n2, p)
    if n2: ans += 2*n2 * solve(c, f+1, n0, n1+1, n2-1, p)
    ans /= tot
  else:
    if n0: ans += n0 * solve(0, 0, n0-1, n1, n2, p+c)
    if n1: ans += n1 * solve(1, 0, n0, n1-1, n2, p+c)
    if n2: ans += n2 * solve(2, 0, n0, n1, n2-1, p+c)
    ans /= rem
  return ans

def q(n):
  return solve(2, 0, 0, 0, n-1, 0)

print("{0:.10f}".format(q(100)))
