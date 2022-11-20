#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

ll MOD = 998244353;
ll N, M, A[201000];

int main() {

  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;

  while (T--) {
    cin >> N >> M;
    for (int i = 0; i < N; i++) cin >> A[i];

    ll cnt = 1;
    for (int i = 1; i < N; i++) {
      if (A[i-1] % A[i] != 0) {
        cnt = 0;
        break;
      }
      // if (A[i] == A[i-1]) {
      //  cnt = (cnt * (M / A[i])) % MOD;
      //  continue;
      // }

      // let k = A[i-1]/A[i]
      // let X = M/A[i] (floor)
      // multiplier = count of (1..X) that are coprime to k
      // use inclusion-exclusion 

      ll k = A[i-1]/A[i];
      vector<ll> pfs;
      for (ll i = 2; i*i <= k; i++) {
        if (k % i == 0) {
          while (k % i == 0) k /= i;
          pfs.push_back(i);
        }
      }
      if (k > 1) pfs.push_back(k);
      k = A[i-1]/A[i];

      ll X = M / A[i];

      ll L = 1ll << pfs.size();
      ll tot = 0;
      for (ll j = 0; j < L; j++) {
        int num = 0;
        ll mult = 1;
        for (int p = 0; p < pfs.size(); p++) {
          if ((j >> p) & 1) {
            mult *= pfs[p];
            num += 1;
          }
        }

        ll change = X / mult;
        tot += num % 2 == 0 ? change : -change;
      }

      cnt = (cnt * tot) % MOD;
    }

    cout << cnt << endl;
  }


  return 0;
}
