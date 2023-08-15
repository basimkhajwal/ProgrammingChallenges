from math import comb

def solve(n, k, s):
    if k == 0: return 1

    idxs = [i for i in range(n) if s[i]]
    if len(idxs) < k: return 1
    idxs.append(n) # dummy value

    ans = comb(idxs[k], k) 
    for i in range(k+1, len(idxs)):
        start = idxs[i - k - 1] + 1
        ans += comb(idxs[i] - start, k)
        ans -= comb(idxs[i-1] - start, k-1)
    return ans % 998244353

if __name__ == "__main__":
    n, k = map(int, input().split())
    s = list(map(int, input()))
    print(solve(n, k, s))
