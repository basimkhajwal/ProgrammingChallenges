#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

string S;

inline bool isPerm() {
  int N = (int)S.size();
  
  bool hasZero = false;
  int t = 0, evenCount = 0;
  for (int i = 0; i < N; i++) {
    int c = S[i]-'0';
    t += c;
    if (c == 0) hasZero = true;
    if (c % 2 == 0) evenCount++;
  }

  return hasZero && t % 3 == 0 && evenCount > 1;
}

int main() {
  int n;
  cin >> n;
  while (n--) {
    cin >> S;
    cout << (isPerm() ? "red\n": "cyan\n");
  }
  return 0;
}
