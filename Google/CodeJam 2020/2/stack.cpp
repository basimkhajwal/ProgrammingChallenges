#include <iostream>
using namespace std;

#define ll long long

inline void solve_slow() {
  ll L, R;
  cin >> L >> R;
  ll i = 0;
  while (max(L,R) >= i) {
    if (L >= R) L -= i;
    else R -= i;
    ++i;
  }
  cout << i << " " << L << " " << R;
}

inline ll triangle(ll n) { return (n*n+n)>>1; }

ll invTri(ll x) {
  ll l = 1, h = 1;
  while (triangle(h) <= x) {
    l=h;
    h+=h;
  }
  while (h-l > 1) {
    ll m = (l + h) >> 1;
    if (triangle(m) <= x) l = m;
    else h = m;
  }
  return l;
}

inline bool feasible(ll& A, ll& B, ll i, ll k, bool modify) {
  ll a = k - k/2;
  ll b = k/2;
  ll a1 = i*a + a + 2*triangle(a-1);
  ll b1 = i*b + 2*triangle(b);
  if (modify) {
    A -= a1;
    B -= b1;
    return A >= 0 && B >= 0;
  }
  return A >= a1 && B >= b1;
}

inline void alternate(ll& A, ll& B, ll& i) {
  ll l = 0, h = invTri(A+B)+1;
  while (h-l > 1) {
    ll m = (l+h)>>1;
    if (feasible(A,B,i,m,false)) l=m;
    else h=m;
  }
  feasible(A,B,i,l,true);
  i+=l;
}

inline void solve() {
  ll L, R;
  cin >> L >> R;

  ll i = L == R ? 0 : invTri(abs(L-R));
  if (L >= R) L -= triangle(i);
  else R -= triangle(i);

  //cout << "Debug: " << i << " " << L << " " << R << endl;
  if (L >= R) alternate(L, R, i);
  else alternate(R, L, i);
  cout << i << " " << L << " " << R;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    cout << "Case #" << t << ": ";
    solve();
    cout << endl;
  }
  return 0;
}
