#include <iostream>
using namespace std;

typedef long long ll;

ll K = 100000000LL;
ll N = K * K;
ll MOD = 1000000007;
// (assume N % K == 0)

inline ll egcd_inv(ll a) {

  ll b = MOD;

  ll s = 1; ll t = 0;
  ll u = 0; ll v = 1;

  while (b) {
    ll q = a / b;
    ll old_b = b;
    ll old_u = u;
    ll old_v = v;

    b = a - q * b;
    a = old_b;

    u = s - q * u;
    v = t - q * v;
    s = old_u;
    t = old_v;
  }

  // a0 * s + b0 * t = (gcd)

  return (s + MOD) % MOD;
}

inline ll fpow(ll a, ll b) {
  ll tot = 1;
  for (; b; b >>= 1) {
    if (b % 2) tot = (tot * a) % MOD;
    a = (a * a) % MOD;
  }
  return tot;
}

int main() {

  ll ans = 0;

  // for 0 <= n2 <= K/2
  //  ans += 2^((K-2*n2)*N/K) * fact(K) / fact(n2) / fact(n2) / fact(K-2*n2)

  ll acc = fpow(2, N);

  ll p2_down = egcd_inv(fpow(2, 2 * N / K));

  for (int n2 = 0; n2 <= K/2; n2++) {
    if (n2) {
      ll n2_inv = egcd_inv(n2);
      n2_inv = (n2_inv * n2_inv) % MOD;
      acc = (acc * p2_down) % MOD;
      acc = (acc * n2_inv) % MOD;

      ll f_inc = K - 2 * n2 + 1;
      acc = (acc * f_inc) % MOD;
      acc = (acc * (f_inc + 1)) % MOD;
    }
    ans += acc;
  }

  cout << (ans % MOD) << endl;

  return 0;
}
