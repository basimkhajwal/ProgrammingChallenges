#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

typedef long long ll;

vector<int> totient;
vector<int> chainLength;
vector<bool> isPrime;

int chain(int k) {
  if (chainLength[k] < 0) {
    if (k == 1) chainLength[k] = 1;
    else {
      chainLength[k] = 1 + chain(totient[k]);
    }
  }
  return chainLength[k];
}


ll solve(int N, int L) {

  isPrime.resize(N, true);
  chainLength.resize(N, -1);

  totient.resize(N, 0);
  for (int i = 0; i < N; i++) totient[i] = i;

  ll ans = 0;

  chainLength[1] = 1;

  for (int p = 2; p < N; p++) {
    if (!isPrime[p]) {
      chainLength[p] = 1 + chainLength[totient[p]];
      continue;
    }
    for (int q = p; q < N; q += p) {
      isPrime[q] = false;
      totient[q] = totient[q] / p * (p-1);
    }
    chainLength[p] = 1 + chainLength[totient[p]];
    if (chainLength[p] == L) ans += p;
  }

  return ans;
}

int main() {
  cout << solve(40000000, 25) << endl;
  return 0;
}
