#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int main() {

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int n, m;
    cin >> n >> m;

    bool hasIsol = false;
    int ii = 1, ij = 1;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        bool isol = true;
        for (int a = -2; a <= 2; a++) {
          for (int b = -2; b <= 2; b++) {
            if (abs(a)+abs(b)==3 && i+a>=0 && j+b>=0 && i+a<n & j+b<n) {
              isol = false;
            }
          }
        }
        if (isol) {
          hasIsol = true;
          ii = i+1;
          ij = j+1;
        }
      }
    }

    cout << ii << " " << ij << endl;
  }

  return 0;
}
