#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int N, A[201000];

int main() {

  int T;
  cin >> T;

  while (T--) {
    cin >> N;
    FOR(i,0,N-1) cin >> A[i];
    sort(A, A+N);

    bool allSame = true;
    FOR(i,1,N-1) allSame = allSame && (A[i] == A[0]);

    if (allSame) {
      cout << N/2 << "\n";
      continue;
    }

    ll ans = 0;
    int i = 0;

    while (i < N) {
      int l = 1;
      while (i+l < N && A[i+l] == A[i]) l++;
      ans = max(ans, ((ll) (i+l)) * (N-i-l));
      i += l;
    }
    cout << ans << "\n";
  }

  return 0;
}
