#include <bits/stdc++.h>
using namespace std;

#define MAXN 123456
#define ll long long

int N;
ll X, K, A[MAXN];

int main() {
    
    ios_base::sync_with_stdio(false);
    
    cin >> N >> X >> K;
    for (int i = 0; i < N; i++) cin >> A[i];
    
    sort(A, A+N);
    
    int lastSame = 0;
    ll total = 0;
    
    for (int i = 0; i < N; i++) {
        if (i && A[i] != A[i-1]) lastSame = i;
        
        int diff = (X - (A[i]%X)) % X;
        ll lower = K ? (A[i] + diff + (K-1)*X) : A[i];
        ll upper = A[i] + diff + K*X; // exclusive upper bound
        
        int a = (int)(lower_bound(A+lastSame, A+N, lower) - A);
        int b = (int)(lower_bound(A+lastSame, A+N, upper) - A);
        
        total += (b-a);
    }
    
    cout << total << endl;
    
    return 0;
}