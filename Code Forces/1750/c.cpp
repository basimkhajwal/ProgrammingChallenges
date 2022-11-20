#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;

int N;
string A, B;

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  while (T--) {
    cin >> N >> A >> B;
    
    int xor1 = 0;
    for (int i = 0; i < N; i++) {
      if ((A[i]=='1')^(B[i]=='1')) xor1++;
    }

    if (xor1 == 0 || xor1 == N) {

      cout << "YES\n";

      vector<int> pos;
      for (int i = 0; i < N; i++) {
        if (A[i] == '1') {
          pos.push_back(i);
        }
      }

      if (pos.size() % 2 != (xor1 == 0 ? 0 : 1)) {
        cout << pos.size()+3 << endl;
        cout << "1 2\n1 1\n2 2\n";;
      } else {
        cout << pos.size() << endl;
      }
      for (int x : pos) {
        cout << x+1 << " " << x+1 << "\n";
      }

    } else {
      cout << "NO\n";
    }
  }

  return 0;
}
