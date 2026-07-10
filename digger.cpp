#include <bits/stdc++.h>
using namespace std;
 
const int MOD = 1000000007;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
 
    vector<vector<int>> dp(n, vector<int>(m, 0));
 
    dp[0][0] = a[0][0];
 
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i == 0 && j == 0)
                continue;
 
            int best = 0;
 
            if (i > 0)
                best = max(best, dp[i - 1][j]);
 
            if (j > 0)
                best = max(best, dp[i][j - 1]);
 
            if (i > 0 && j > 0)
                best = max(best, dp[i - 1][j - 1]);
 
            dp[i][j] = best + a[i][j];
        }
    }
 
    cout << dp[n - 1][m - 1];
 
    return 0;
}
