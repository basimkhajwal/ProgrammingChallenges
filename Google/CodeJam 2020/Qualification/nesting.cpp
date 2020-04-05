#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    string S;
    cin >> S;
    cout << "Case #" << t << ": ";
    int d = 0;
    for (int i = 0; i < (int)S.size(); i++) {
      int v = S[i]-'0';
      for (; d < v; d++) cout << '(';
      for (; d > v; d--) cout << ')';
      cout << v;
    }
    while (d--) cout << ')';
    cout << endl;
  }
  return 0;
}
