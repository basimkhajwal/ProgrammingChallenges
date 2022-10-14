#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int N, K, P[201000];
vector<int> C[201000];

pair<int,int> minCuts(int v, int d) {
  int totCuts = 0;
  int childDepth = 0;
  for (int u : C[v]) {
    pair<int,int> ans = minCuts(u, d);
    totCuts += ans.first;

    if (ans.second + 1 == d && v != 1) {
      totCuts += 1;
    } else {
      childDepth = max(childDepth, 1 + ans.second);
    }
  }
  return make_pair(totCuts, childDepth);
}

int main() {
  int T;
  cin >> T;

  while (T--) {
    cin >> N >> K;
    for (int i = 0; i <= N; i++) C[i].clear();

    P[1] = 0;
    for (int i = 2; i <= N; i++) {
      cin >> P[i];
      C[P[i]].push_back(i);
    }

    int l = 0; // not possible
    int u = N-1; // possible

    while (u-l > 1) {
      int m = (u+l) / 2;
      if (minCuts(1, m).first <= K) {
        u = m;
      } else {
        l = m;
      }
    }

    cout << u << endl;
  }

  return 0;
}
