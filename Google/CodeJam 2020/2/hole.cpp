#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
#define pll pair<long long,long long>

pll getBearing(pll u, pll v) {
  return make_pair(v.first-u.first, v.second-u.second);
}

ll dist2(pll a, pll b) {
  return (a.first-b.first)*(a.first-b.first) + (a.second-b.second)*(a.second-b.second);
}

bool sameBearing(pll a, pll b) {
  return a.first*b.second == a.second*b.first;
}

int N; 
pll P[100];
int W[100];
ll ANS;
vector<pll> bs;

void go(int a) {
  if (a==N) {
    for (auto b: bs) {
      for (int i = 0; i < N; i++) {
        int j = i;
        ll cnt = 1;
        while (W[j] != -1) {
          j = W[j];
          cnt+=1;
          int fst = -1;
          for (int k = 0; k < N; k++) {
            if (sameBearing(getBearing(P[j], P[k]), b)) {
              if (fst == -1 || dist2(P[j], P[k]) < dist2(P[j], P[fst])) {
                fst = k;
              }
            }
          }
          if (fst != -1) {
            j = fst;
            cnt+=1;
          } else {
            break;
          }
        }
        ANS = max(cnt, ANS);
      }
    }
    return;
  }
  go(a+1);
  for (int i = a+1; i < N; i++) {
    W[a] = i;
    W[i] = a;
    go(i+1);
    W[a] = W[i] = -1;
  }
}

inline ll solve() {
  for (int i = 0; i < N; i++) W[i] = -1;
  for (int i = 0; i < N; i++) {
    for (int j = i+1; j < N; j++) {
      bs.push_back(getBearing(P[i], P[j]));
    }
  }
  go(0);
  return ANS;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cin >> N;
    for (int i = 0; i < N; i++) cin >> P[i].first >> P[i].second;
    ll ans = solve();
    cout << "Case #" << t << ": " << ans << endl;
  }
  return 0;
}
