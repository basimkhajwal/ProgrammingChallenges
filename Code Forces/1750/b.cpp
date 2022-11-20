#include <iostream>
using namespace std;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  while (T--) {
    long long n;
    cin >> n;
    string s;
    cin >> s;

    char p = 0;
    long long l = 0, max_l = 0;
    long long x = 0;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') x++;
      if (s[i] != p) l = 0;
      l++;
      if (l > max_l) max_l = l;
      p = s[i];
    }

    cout << max(x*(n-x), max_l*max_l) << endl;
  }

  return 0;
}
