#include <iostream>
#include <cstdlib>
using namespace std;

typedef long long ll;
ll d_cubed[1000000];

inline ll max_cube(ll n) {
  ll a = 1;
  ll b = min(n, 1000000LL);
  while (b-a > 1) {
    ll c = (a+b)/2;
    if (c*c*c < n) a = c;
    else b = c;
  }
  return a;
}

inline ll d(ll n) {
  ll t = 0;
  while (n > 1) {
    ll k = max_cube(n);
    t += d_cubed[k];
    n -= k*k*k;
    t += n;
  }
  return t;
}

void solve(ll N) {
  d_cubed[0] = d_cubed[1] = 0;
  ll k = max_cube(N);
  for (ll i = 2; i <= k; i++) d_cubed[i] = d(i*i*i);
  cout << d(N) << endl;
}

int main() {
  solve(100000000000000000LL);
  return 0;
}
