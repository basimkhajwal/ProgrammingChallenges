#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXN 101000

int R, N, T[MAXN], X[MAXN], Y[MAXN], DP[MAXN];

inline int mandist(int a, int b, int c, int d) {
  return abs(c-a) + abs(d-b);
}

inline int dist_idx(int i, int j) {
  return mandist(X[i], Y[i], X[j], Y[j]);
}

int main() {

  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> R >> N;
  for (int i = 0; i < N; i++) {
    cin >> T[i] >> X[i] >> Y[i];
  }

  int v = 0;
  int k = N;
  DP[N-1] = 1;
  for (int i = N-2; i >= 0; --i) {
    while (k > i && T[k-1] - T[i] >= 1000) v = max(v, DP[--k]);
    DP[i] = 1 + v;
    for (int j = i+1; j < k; j++) {
      if (T[i]+dist_idx(i,j)<=T[j]) {
        DP[i] = max(DP[i], DP[j] + 1);
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (mandist(1, 1, X[i], Y[i]) <= T[i]) {
      ans = max(ans, DP[i]);
    }
  }
  cout << ans << endl;

  return 0;
}
