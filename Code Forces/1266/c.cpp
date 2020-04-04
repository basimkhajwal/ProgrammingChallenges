#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int R, C;

int main() {

  cin.tie(NULL);
  cout.tie(NULL);
  ios_base::sync_with_stdio(false);

  cin >> R >> C;

  if (R == 1 && C == 1) {
    cout << "0\n";
    return 0;
  }

  if (C == 1) {
    for (int r = 1; r <= R; r++) cout << (r+1) << "\n";
    return 0;
  }

  for (int r = 1; r <= R; r++) {
    for (int c = 1; c <= C; c++) {
      cout << (R+c)*r;
      if (c < C) cout << " ";
      else cout << "\n";
    }
  }

  return 0;
}
