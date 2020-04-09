#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

#define MAXN 201000
#define MOD 998244353

int N, K, P[MAXN];

int main() {

  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N >> K;
  REP(i,N) {
    int x;
    cin >> x;
    P[x] = i;
  }

  ll tot = 0;
  ll ways = 1;
  vector<int> pos;
  REP (i,K) {
    int j = N+1-i;
    tot += j;
    pos.push_back(P[j]);
  }

  sort(pos.begin(), pos.end());
  REP(i,K-1) ways = (ways * (pos[i] - pos[i-1])) % MOD;

  cout << tot << " " << ways << endl;

  return 0;
}
