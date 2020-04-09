#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int lps[2100000];

string revStr(string a) {
  string b(a);
  reverse(b.begin(), b.end());
  return b;
}

string maxPrefixPal(string s0) {
  int n = (int)s0.size();
  /* Easy O(n^2)
  for (int l = n; l > 0; --l) {
    bool works = true;
    for (int i = 0; works && i < l/2; i++) {
      works = s[i] == s[l-i-1];
    }
    if (works) return s.substr(0, l);
  }
  return "-1"; */

  string s = s0 + revStr(s0);
  int len = 0;
  lps[0] = 0;
  int i = 1;
  while (i < 2*n) {
    if (s[i] == s[len]) {
      len++;
      lps[i] = len;
      i++;
    }
    else if (len != 0) {
      len = lps[len - 1];
    }
    else {
      lps[i] = 0;
      i++;
    }
  }
  return s.substr(0, min(len, n));
}

int main() {

  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;

  while (T--) {
    string S;
    cin >> S;
    int N = (int)S.size();

    int a = 0;
    while (a+a < N && S[a] == S[N-1-a]) a++;

    string s1 = S.substr(0, a);
    if (a+a >= N) {
      if (a+a==N) cout << s1 + revStr(s1) << "\n";
      else cout << s1.substr(0,a-1) + revStr(s1) << "\n";
      continue;
    }

    S = S.substr(a, N-2*a);
    string s2 = maxPrefixPal(S);
    string s3 = maxPrefixPal(revStr(S));
    string s4 = s2.size() < s3.size() ? s3 : s2;
    cout << s1 << s4 << revStr(s1) << "\n";
  }

  return 0;
}
