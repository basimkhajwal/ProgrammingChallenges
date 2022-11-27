#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

inline ll gcd(ll a, ll b) {
  ll c;
  while (b) {
    c = a % b;
    a = b;
    b = c;
  }
  return a;
}

int main() {

  int T;
  cin >> T;

  while (T--) {
    int N, a, g, m;
    cin >> N;
    cin >> g;
    m = g;
    FOR(i, 1, N-1) {
      cin >> a;
      g = gcd(g, a);
      m = max(m, a);
    }
    cout << (m / g) << "\n";
  }

  return 0;
}
