#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int C, D, X[100], T[100], L[1000];
vector<pair<int,int>> adj[100];

inline void input() {
  cin >> C >> D;
  X[0] = 0;
  for (int i = 1; i < C; i++) cin >> X[i];
  for (int i = 0; i < C; i++) adj[i].clear();
  for (int i = 0; i < D; i++) {
    int u, v;
    cin >> u >> v;
    u--; v--;
    adj[u].push_back(make_pair(v, i));
    adj[v].push_back(make_pair(u, i));
  }
}

inline void solve() {
  vector<int> ord;
  int negCount = 0;
  for (int i = 0; i < C; i++) {
    ord.push_back(i);
    if (X[i] < 0) negCount++;
  }
  sort(ord.begin(), ord.end(), [&](int a, int b) { return X[a] < X[b]; });
  for (int i = negCount-1; i >= 0; i--) {
    int k = -X[ord[i]];
    for (int j = 0; j < k; j++) swap(ord[i+j], ord[i+j+1]);
  }

  vector<int> ordInv(C);
  for (int i = 0; i < C; i++) ordInv[ord[i]] = i;

  int t = 0;
  for (int i = 0; i < C; i++) {
    int u = ord[i];
    if (i == 0 || X[ord[i]] != X[ord[i-1]]) {
      t++;
    } 
    T[u] = t = max(t, X[u]);
    for (auto& edge: adj[u]) {
      int v = edge.first, idx = edge.second;
      if (ordInv[u] < ordInv[v]) continue;
      // cout << u << " " << v << " " << X[u] << " " << X[v] << endl;
      L[idx] = max(T[u] - T[v], 1);
    }
  }
  /*
  cout << "Debug time ";
  for (int i = 0; i < C; i++) {
  cout << " " << X[i];
  }
  cout << endl;*/
}

inline void output(int t) {
  cout << "Case #" << t << ":";
  for (int i = 0; i < D; i++) cout << " " << L[i];
  cout << endl;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    input();
    solve();
    output(t);
  }
  return 0;
}
