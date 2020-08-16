#include <iostream>
using namespace std;

#define MAX 10000000
#define MOD 1000000

// p[i] - number of palindromes summing to i
// tp[i] - number of two palindromes summing to i
int p[MAX], tp[MAX];

// Slow quadratic recurrence
void direct() {
  for (int i = 0; i < MAX; i++) {
    // Count odd cases (and zero case for p)
    p[i] = 1;
    tp[i] = i == 2 ? 1 : 0;
    // Count even cases recursively (modding to save space)
    for (int j = 2; j <= i; j+=2) {
      p[i] += p[i-j];
      tp[i] += j == 4 ? p[i-j] : tp[i-j];
      p[i] %= MOD;
      tp[i] %= MOD;
    }
    cout << i << " " << tp[i] << endl;
    if (i > 42 && tp[i] == 0) {
      cout << i << endl;
      break;
    }
  }
}

// Some algebra gets a linear solution
void faster() {
  p[0] = p[1] = 1;
  for (int i = 2; i < MAX; i+=2)  {
    p[i] = p[i+1] = (p[i-1] << 1) % MOD;
  }

  for (int i = 0; i < MAX; i++) {
    if (i > 2) tp[i] += tp[i-2] << 1;
    if (i == 2) tp[i]++;
    if (i == 4) tp[i]--;
    if (i >= 4) tp[i] += p[i-4] - tp[i-4];
    if (i >= 6) tp[i] -= p[i-6] - tp[i-6];
    tp[i] %= MOD;

    if (i > 42 && tp[i] == 0) {
      cout << i << endl;
      break;
    }
  }
}

int main() {

  // direct();
  faster();

  return 0;
}

