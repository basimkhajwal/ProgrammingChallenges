import math

"""
A pisano period of length n happens
only if fib(n)=fib(n+1)=1 mod k
(start with fib(n)=fib(2n) and fib(n+1)=fib(2n+1) 
mod k and work backwards)

This is iff k divides both fib(n)-1 and fib(n+1)-1
Which is iff k divides gcd(fib(n)-1,fib(n+1)-1)

Finally for all such k, check if we actually have
period n (we could have period < n).
"""

def cycle_length(start, get_next):
    t = get_next(start)
    h = get_next(t)
    i = 1
    while t != h:
        t = get_next(t)
        h = get_next(get_next(h))
        i += 1
    return i

def period(n):
    start = (1, 1)
    def get_next(x):
        return x[1], ((x[0]+x[1]) % n)
    return cycle_length(start, get_next)

def fib(n):
    a = b = 1
    for _ in range(n): a, b = b, a + b
    return a

def divisors(n):
    a = 1
    while a*a < n:
        if n % a == 0:
            yield a
            yield n // a
        a += 1
    if n % a == 0: yield a

def solve(k, M):
    x1 = fib(k) 
    x2 = fib(k+1) 
    x = math.gcd(x1-1,x2-1)
    t = 0
    for d in divisors(x):
        if d < M and period(d)==k:
            t += d
    return t

print(solve(120, 1000000000))

