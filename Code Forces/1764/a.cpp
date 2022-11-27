#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int main() {

  int T;
  cin >> T;

  while (T--) {
    int N, a;
    cin >> N;
    FOR(i, 0, N-1) cin >> a;
    cout << 1 << " " << N << "\n";
  }

  return 0;
}
