#include <iostream>
 
using namespace std;
 
const long long MOD = 1000000007;
 
long long binpow(long long a, long long b) {
    long long res = 1;
 
    while (b > 0) {
        if (b & 1)
            res = res * a % MOD;
 
        a = a * a % MOD;
        b >>= 1;
    }
 
    return res;
}
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int N;
    cin >> N;
 
    long long sum = 0;
 
    for (int i = 0; i < N; i++) {
        long long x;
        cin >> x;
        sum = (sum + x) % MOD;
    }
 
    if (sum < 0)
        sum += MOD;
 
    long long cnt = binpow(2, N - 1);
 
    cout << (sum * cnt) % MOD;
 
    return 0;
}
