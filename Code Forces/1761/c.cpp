#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> G[101], A[101];

void dfs(int n, int v) {
  vector<int>& a = A[n];
  if (a.size() == 0 || a[a.size()-1] != v) {
    a.push_back(v);
    for (int m : G[n]) dfs(m, v);
  }
}

int main() {

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    cin >> N;

    for (int i = 0; i < N; i++) {
      string S;
      cin >> S;
      G[i].clear();
      A[i].clear();
      for (int j = 0; j < N; j++) {
        if (S[j] == '1') {
          G[i].push_back(j);
        }
      }
    }

    for (int i = 0; i < N; i++) dfs(i, i);

    for (int i = 0; i < N; i++) {
      cout << A[i].size();
      for (int x : A[i]) cout << " " << x+1;
      cout << "\n";
    }
  }

  return 0;
}
