from decimal import *

def tau(theta, n=100):
  b = theta
  s = str(int(b)) + "."
  for i in range(1,n):
    b = int(b) * (b - int(b) + 1)
    s += str(int(b))
  return Decimal(s)

x = Decimal(2)
for i in range(10):
  x = tau(x)
  print(f"{i} {x:.25f}")