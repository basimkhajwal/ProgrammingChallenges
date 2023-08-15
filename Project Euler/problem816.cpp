#include <cstdlib>
#include <iostream>
#include <tuple>
#include <vector>
using namespace std;

#define ll long long

const ll S0 = 290797;
const ll M = 50515093;
const float PI = 3.14159265;

typedef pair<ll,ll> point;
typedef vector<vector<vector<point>>> grid;

ll dist2(const point& a, const point& b) {
  ll x = a.first - b.first;
  ll y = a.second - b.second;
  return x*x + y*y;
}

double solve(int N) {
  ll B = M / (ll)sqrt(PI * N);
  int k = (M+B-1) / B;
  grid grid;
  for (int i = 0; i < k; i++) {
    vector<vector<point>> row;
    for (int j = 0; j < k; j++) {
      vector<point> col;
      row.push_back(col);
    }
    grid.push_back(row);
  }

  ll a = 0, b = S0;
  ll ans = M * M * 4;
  for (int i = 0; i < N; i++) {
    a = b;
    b = (b * b) % M;
    if (i % 2 == 0) {
      int a1 = a / B;
      int b1 = b / B;
      point pt0 = make_pair(a,b);

      for (int r = max(a1-1,0); r < min(a1+1, k); r++) {
        for (int c = max(b1-1,0); c < min(b1+1, k); c++) {
          for (const point& pt1 : grid[r][c]) {
            ans = min(ans, dist2(pt0, pt1));
          }
        }
      }

      grid[a1][b1].push_back(pt0);
    }
  }

  return sqrt(ans);
}

int main() {
  
  printf("%.09f\n", solve(4000000));

  return 0;
}
