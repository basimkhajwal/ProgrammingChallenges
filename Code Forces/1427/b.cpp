#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
string S;

int main() {

  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int T;
  cin >> T;

  while (T--) {
    cin >> N >> K >> S;

    vector<int> chunks;
    int first_chunk = 0, last_chunk = 0;
    bool is_first = true;

    int cl = 0; 
    int score = 0;

    for (int i = 0; i < N; i++) {
      if (S[i] == 'W') {
        score += (is_first || cl > 0) ? 1 : 2;
        if (is_first) {
          first_chunk = cl;
        } else if (cl > 0) {
          chunks.push_back(cl);
        }
        is_first = false;
        cl = 0;
      } else {
        cl++;
      }
    }
    last_chunk = cl;

    if (score == 0) {
      score = K > 1 ? 2*K-1 : K;
    } else {
      sort(chunks.begin(), chunks.end());
      for (int i = 0; i < chunks.size(); i++) {
        if (chunks[i] <= K) {
          K -= chunks[i];
          score += chunks[i]*2 + 1;
        } else {
          score += K*2;
          K = 0;
          break;
        }
      }
      score += 2*min(K, first_chunk + last_chunk);
    }

    cout << score << "\n";
  }

  return 0;
}
