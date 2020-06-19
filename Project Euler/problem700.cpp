/**
   Idea:
     Iterate finding Euler coins until small enough, then
     use modular inverse to calculate first-seen-time for
     each smaller value and then sum over remaining Euler coins.

   Runs in about 1.39s
 */
#include <iostream>
#include <vector>
using namespace std;

#define ll long long

ll modinv(ll a, ll b) {
  ll s = 1, t = 0;
  ll u = 0, v = 1;

  while (b) {
    ll q = a / b;
    ll r = a - q * b;
    a = b;
    b = r;

    ll old_s = s, old_t = t;
    s = u;
    t = v;
    u = old_s - q * u;
    v = old_t - q * v;
  }

  return s;
}

const ll N = 1504170715041707;
const ll M = 4503599627370517;
const ll CUT_OFF = 100000000;

int main() {
  ll ans = 0;
  ll a = N, min_so_far = N;
  ans += N;

  while (a >= CUT_OFF) {
    a = (a+N) % M;
    if (a < min_so_far) {
      min_so_far = a;
      ans += a;
    }
  }

  ll N_inv = modinv(N, M);
  N_inv %= M;
  if (N_inv < 0) N_inv += M;

  ll size = min_so_far;
  vector<pair<ll, int>> firsts(size);
  firsts[0] = make_pair(M, 0);
  firsts[1] = make_pair(N_inv, 1);
  for (int i = 2; i < size; i++) {
    firsts[i].first = (firsts[i-1].first + N_inv) % M;
    firsts[i].second = i;
  }
  sort(firsts.begin(), firsts.end());

  for (int i = 0; i < size; i++) {
    int x = firsts[i].second;
    if (x < min_so_far) {
      min_so_far = x;
      ans += x;
    }
  }
  cout << ans << endl;

  return 0;
}
