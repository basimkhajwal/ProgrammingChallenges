#include <iostream>
using namespace std;

int N, A[1000][2];
int C[1000];

inline bool overlaps(int u, int v) {
  return A[v][0] < A[u][1] && A[u][0] < A[v][1];
}

bool dfs(int u, int c) {
  if (C[u] != -1) return C[u] == c;
  C[u] = c;
  for (int v = 0; v < N; v++) {
    if (u != v && overlaps(u, v)) {
      if (!dfs(v, 1-c)) return false;
    }
  }
  return true;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> A[i][0] >> A[i][1];
    for (int i = 0; i < N; i++) C[i] = -1;

    bool possible = true;
    for (int i = 0; i < N && possible; i++) {
      if (C[i] == -1) possible = dfs(i, 0);
    }

    cout << "Case #" << t << ": ";
    if (possible) {
      for (int i = 0; i < N; i++) cout << "CJ"[C[i]];
    } else {
      cout << "IMPOSSIBLE";
    }
    cout << endl;
  }
  return 0;
}
