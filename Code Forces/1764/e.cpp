#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int N, K, A[101000], B[101000];
vector<pair<int,int>> p;

inline bool solve() {
  if (A[0] + B[0] < K) return false;
  if (K <= A[0]) return true;
  if (N == 1) return false;
  int m = K - B[0];
  int prev = -1;
  for (auto x : p) {
    int c = -x.first;
    int b = -x.second;
    int a = c - b;
    if (prev != -1) {
      if (m <= c) return true;
      m -= prev;
    }
    if (c < m) return false;
    if (a >= m) return true;
    prev = b;
  }
  return false;
}

int main() {

  int T;
  cin >> T;

  while (T--) {
    cin >> N >> K;
    p.clear();
    FOR(i,0,N-1) {
      cin >> A[i] >> B[i];
      if (i > 0) p.push_back(make_pair(-A[i]-B[i], -B[i]));
    }
    sort(p.begin(), p.end());
    cout << (solve() ? "YES\n" : "NO\n");
  }

  return 0;
}
