#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define REP(i,n) FOR(i,1,n)
#define ll long long

int N;
ll A[300000], B[300000];

int main() {

  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  for (int i = 1; i <= N; i++) cin >> B[i];

  ll m = 0;
  for (int i = 1; i <= N; i++) {
    A[i] = B[i] + m;
    if (A[i] > m) m = A[i];
  }

  cout << A[1];
  for (int i = 2; i <= N; i++) cout << " " << A[i];
  cout << endl;

  return 0;
}
