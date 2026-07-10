#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    vector<int> cnt(8);
 
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
 
    if (cnt[5] || cnt[7]) {
        cout << -1;
        return 0;
    }
 
    vector<vector<int>> ans;
 
    while (cnt[4] > 0) {
        if (cnt[1] == 0 || cnt[2] == 0) {
            cout << -1;
            return 0;
        }
        cnt[1]--;
        cnt[2]--;
        cnt[4]--;
        ans.push_back({1, 2, 4});
    }
 
    while (cnt[3] > 0) {
        if (cnt[1] == 0 || cnt[6] == 0) {
            cout << -1;
            return 0;
        }
        cnt[1]--;
        cnt[3]--;
        cnt[6]--;
        ans.push_back({1, 3, 6});
    }
 
    while (cnt[6] > 0) {
        if (cnt[1] == 0 || cnt[2] == 0) {
            cout << -1;
            return 0;
        }
        cnt[1]--;
        cnt[2]--;
        cnt[6]--;
        ans.push_back({1, 2, 6});
    }
 
    if (cnt[1] || cnt[2] || cnt[3] || cnt[4] || cnt[5] || cnt[6] || cnt[7]) {
        cout << -1;
        return 0;
    }
 
    for (auto &v : ans)
        cout << v[0] << " " << v[1] << " " << v[2] << '\n';
 
    return 0;
}
