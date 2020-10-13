// Nice derivation shows f(k) is the highest prime
// factor of k+1, minus 1.
// Use the factorisation k^3+1 = (k+1)(k^2-k+1) to
// efficiently solve it.
// Still fairly compute heavy - takes 3m to run

#include <iostream>
#include <vector>
using namespace std;

#define ll long long

#define N 2000000
#define M 10000000

ll maxPF[M];
vector<ll> primes;

inline ll hpf(ll k) {
  ll i = 0;
  while (primes[i]*primes[i] <= k) {
    if (k < M) return maxPF[k];
    while (k > primes[i] && k % primes[i] == 0) {
      k /= primes[i];
    }
    ++i;
  }
  return k;
}

int main() {

  for (ll i = 2; i < M; i++) {
    if (maxPF[i]) continue;
    primes.push_back(i);
    for (ll j = i; j < M; j+=i) maxPF[j] = i;
  }

  ll t = 0;
  for (ll i = 1; i <= N; i++) {
    t += max(hpf(i+1), hpf(i*i-i+1)) - 1;
  }
  cout << t << endl;

  return 0;
}
