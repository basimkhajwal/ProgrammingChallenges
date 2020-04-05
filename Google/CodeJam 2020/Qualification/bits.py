def query(idx):
  print(idx+1,flush=True)
  return int(input())

# Map array elements via 0 -> 1, 1 -> 0, -1 -> -1
def negate(arr): return [[1,0,-1][x] for x in arr]

def run():
  T,B=map(int,input().split())

  # Alternate back and front over the array to maximise overlap
  # between possibilities when considering if the array is reversed
  def pos(i): return [i//2, B-1-i//2][i % 2]

  def solve():
    A = [-1] * B
    cnt = 0
    while True:
      i = 0
      while i < B and cnt < 10:
        while i < B and A[pos(i)] != -1: i += 1
        if i == B: break
        A[pos(i)] = query(pos(i))
        cnt += 1
        i += 1
      if i == B: break

      # Filter out possibilities with at most 2 queries
      poss = [A, A[::-1], negate(A), negate(A)[::-1]]

      a0 = query(0)
      cnt = 1
      poss = [arr for arr in poss if arr[0] == a0]
      
      diff = -1
      for j in range(B):
        if poss[0][j] != poss[1][j] and poss[0][j] != -1 and poss[1][j] != -1:
          diff = j
          break
      if diff >= 0:
        a1 = query(diff)
        cnt += 1
        A = poss[0] if poss[0][diff] == a1 else poss[1]
      else:
        # Take locations that are the same (at most 1 position is lost)
        A = [poss[0][j] if poss[0][j] == poss[1][j] else -1 for j in range(B)]
    return A

  for t in range(1,T+1):
    arr = solve()
    print(''.join(map(str,arr)), flush=True)
    if input() == "N": break

run()
