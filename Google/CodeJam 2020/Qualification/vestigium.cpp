#include <cstdio>
#include <set>
using namespace std;

int N, A[100][100];

int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        scanf("%d", &A[i][j]);
      }
    }
    int r = 0, c = 0, k = 0;
    for (int i = 0; i < N; i++) {
      set<int> row, col;
      for (int j = 0; j < N; j++) {
        row.insert(A[i][j]);
        col.insert(A[j][i]);
      }
      if (row.size() < N) r++;
      if (col.size() < N) c++;
      k += A[i][i];
    }
    printf("Case #%d: %d %d %d\n", t, k, r, c); 
  }
  return 0;
}
