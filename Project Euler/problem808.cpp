// Simple brute force worked but there must
// be something smarter.
#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

// Take primes up to this
#define MAX_SEARCH 50000000

typedef long long ll;

vector<ll> primes;
bool isComposite[MAX_SEARCH];


inline ll rev_digits(ll n) {
  ll m = 0;
  while (n) {
    m = m * 10 + (n % 10);
    n /= 10;
  }
  return m;
}

inline ll int_sqrt(ll n) {
  return (ll)sqrt(n * 1.0);
}

int main() {

  isComposite[0] = isComposite[1] = true;
  for (ll i = 2; i < MAX_SEARCH; i++) {
    if (isComposite[i]) continue;
    primes.push_back(i);
    for (ll j = i*i; j < MAX_SEARCH; j+=i) isComposite[j] = true;
  }

  int i = 0;
  ll ans = 0;

  for (ll p : primes) {
    ll x = rev_digits(p*p);
    ll q = int_sqrt(x);
    if (q != p && q*q == x && !isComposite[q]) {
      ans += p*p;
      if (++i == 50) break;
    }
  }

  cout << i << " " << ans << endl;

  return 0;
}


