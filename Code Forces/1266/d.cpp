// Overly complex solution (don't need to maintain original graph structure as this does)
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <tuple>
#include <set>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

#define MAXN 101000

int N, M;
map<int,ll> adj[MAXN];
set<int> debtors[MAXN];

inline void add_debt(int u, int v, ll d) {
  adj[u][v] = adj[u].count(v) ? adj[u][v]+d : d;
  if (adj[u][v] > 0) debtors[v].insert(u);
}

int main() {

  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> N >> M;
  REP(i, M) {
    int u,v;
    ll d;
    cin >> u >> v >> d;
    add_debt(u, v, d);
  }

  vector<int> nums(N);
  REP(i,N) nums[i-1]=i;
  random_shuffle(nums.begin(), nums.end());

  for (int u : nums) {
    auto it = debtors[u].begin();
    vector<int> to_erase;
    for (auto e: adj[u]) {
      int v = e.first;
      while (it != debtors[u].end() && adj[u][v] > 0) {
        int w = *it;
        ll d = min(adj[w][u], adj[u][v]);
        adj[u][v] -= d;
        adj[w][u] -= d;
        if (adj[w][u] == 0) {
          adj[w].erase(u);
          ++it;
        }
        if (w != v) add_debt(w, v, d);
      }
      if (adj[u][v] == 0) {
        to_erase.push_back(v);
        debtors[v].erase(u);
      }
      if (it == debtors[u].end()) break;
    }
    debtors[u].clear();
    for (int v: to_erase) adj[u].erase(v);
  }

  vector<tuple<int,int,ll>> ans;
  REP(u,N) {
    for (auto const& e: adj[u]) {
      if (e.second > 0) ans.push_back({u, e.first, e.second});
    }
  }

  cout << ans.size() << endl;
  for (auto x: ans) cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << "\n";

  return 0;
}
