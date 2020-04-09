#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n == 1) cout << "-1\n";
    else {
      if (n % 9 == 1) cout << "2";
      else cout << "5";
      for (int i = 0; i < n-2; i++) cout << "5";
      cout << "9\n";
    }
  }
  return 0;
}
