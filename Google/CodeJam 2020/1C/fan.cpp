#include <iostream>
#include <cmath>
using namespace std;

void solve() {
  int X, Y, N;
  string M;
  cin >> X >> Y >> M;
  N = (int)M.size();
  for (int i = 0; i <= N; i++) {
    if (abs(X) + abs(Y) <= i) {
      cout << i;
      return;
    }
    if (i < N) {
      if (M[i] == 'N') Y++;
      if (M[i] == 'E') X++;
      if (M[i] == 'S') Y--;
      if (M[i] == 'W') X--;
    }
  }
  cout << "IMPOSSIBLE";
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    solve();
    cout << endl;
  }
  return 0;
}
