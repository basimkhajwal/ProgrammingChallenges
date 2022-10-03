#include <iostream>
using namespace std;

typedef long long ll;

const ll N = 200000000;
const ll TARGET = 5000000;
bool isComposite[N];

inline int xor_mul(int a, int b) {
  int c = 0;
  for (; b; b >>= 1, a <<= 1) {
    c ^= a * (b & 1);
  }
  return c;
}

int main() {

  int cnt = 1; // include 2 already

  for (ll i = 3; i < N; i+=2) {
    if (isComposite[i]) continue;
    if (++cnt == TARGET) {
      cout << i << endl;
      return 0;
    }
    for (ll j = i; j*i <= 4*N; j+=2) {
      int x = xor_mul(i, j);
      if (x < N) isComposite[x] = true;
    }
  }

  cout << "Not found" << endl;

  return 0;
}
