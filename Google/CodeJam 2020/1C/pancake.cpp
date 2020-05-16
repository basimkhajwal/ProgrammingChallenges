#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

#define ll long long

const ll MAX = 36000000000000LL;
const int MAX_RT = 6000000;

vector<ll> primes;
bool isComposite[MAX_RT+1];

void sievePrimes() {
  isComposite[0] = isComposite[1] = false;
  for (ll i = 2; i <= MAX_RT; i++) {
    if (isComposite[i]) continue;
    primes.push_back(i);
    for (ll j = i*i; j <= MAX_RT; j++) isComposite[j] = true;
  }
}

vector<pair<ll,int>> primeFactorise(ll n) {
  vector<pair<ll,int>> ans;
  for (int i = 0; i < primes.size() && primes[i]*primes[i] <= n; i++) {
    int d = 0;
    for (; n % primes[i] == 0; d++) n /= primes[i];
    if (d) ans.push_back(make_pair(primes[i], d));
  }
  if (n > 1) ans.push_back(make_pair(n, 1));
  return ans;
}

vector<ll> getFactors(ll n) {
  vector<pair<ll,int>> pf = primeFactorise(n);
  vector<ll> ans;
  ans.push_back(1);
  for (pair<ll,int> x: pf) {
    for (ll a: ans) {
      ll p = 1;
      for (int d = 1; d <= x.second; d++) {
        p *= x.first;
        ans.push_back(a * p);
      }
    }
  }
  return ans;
}

int N, D;
ll A[10000];

bool validSize(ll d) {
  ll t = 0;
  for (int i = 0; i < N; i++) {
    t += A[i]/d;
  }
  return t>=D;
}

ll countCuts(ll d) {
  ll t = D;
  ll c = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] % d == 0) {
      ll v = A[i] / d;
      if (t < v) return c+t;
      if (t == v) return c+t-1;
      t -= v;
      c += v-1;
    }
  }
  for (int i = 0; i < N; i++) {
    if (A[i] % d != 0) {
      ll v = min(t, A[i] / d);
      t -= v;
      c += v;
      if (t == 0) return c;
    }
  }
  return c;
}

ll solve() {
  cin >> N >> D;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i] *= D;
  }
  sort(A, A+N);

  set<ll> factors;
  for (int i = 0; i < N; i++) {
    vector<ll> fs = getFactors(A[i]);
    copy(fs.begin(), fs.end(), inserter(factors, factors.end()));
  }

  ll ans = 1000000000;
  for (ll f: factors) {
    // cout << f << endl;
    if (validSize(f)) {
      ll k = countCuts(f);
      // cout << f << " " << k << endl;
      ans = min(ans, k);
    }
  }
  return ans;
}

int main() {
  //ios_base::sync_with_stdio(false);
  //cin.tie(0);
  sievePrimes();
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}
