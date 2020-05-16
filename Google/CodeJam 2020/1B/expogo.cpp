#include <iostream>
#include <cmath>
using namespace std;

inline bool move(int& a, int& b) {
  bool pos = a > 0;
  if ((abs((a/2) % 2) != abs((b/2) % 2)) || (a/2 == 0 && b/2 == 0))  {
    a /= 2;
    b /= 2;
    return pos;
  } else {
    a /= 2;
    b /= 2;
    a += pos ? 1 : -1;
    return !pos;
  }
}

string solve() {
  int X, Y;
  cin >> X >> Y;
  string ans = "";
  while (X != 0 || Y != 0) {
    if (abs(X % 2) == abs(Y % 2)) return "IMPOSSIBLE";
    if (X % 2) ans += move(X, Y) ? 'E' : 'W';
    else ans += move(Y, X) ? 'N' : 'S';
  }
  return ans;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}
