#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

inline bool possible(ll N) {
  if (N < 15) return false;
  ll k = N % 14;
  return k >= 1 && k <= 6;
}

int main() {

  int T;
  cin >> T;

  while (T--) {
    ll N;
    cin >> N;
    cout << (possible(N) ? "YES\n" : "NO\n");
  }

  return 0;
}
