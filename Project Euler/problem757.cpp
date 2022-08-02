#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int solve(ll maxN) {
  vector<ll> res;
  for (ll k = 1; k < 5000; ++k) {
    for (ll a = k;; a++) {
      ll n = a * (a+1) * k * (k+1);
      if (n > maxN) break;
      res.push_back(n);
    }
  }
  sort(res.begin(), res.end());
  int tot = 1;
  for (int i = 1; i < res.size(); i++) {
    if (res[i] != res[i-1]) ++tot;
  }
  return tot;
}

int main() {
  cout << solve(100000000000000LL) << endl;
  // cout << solve(1000000LL) << endl;
  return 0;
}
