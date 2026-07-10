#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
 
    vector<int> local_min, local_max;
 
    for (int i = 0; i < n; ++i) {
        bool isMin = true, isMax = true;
 
        if (i > 0) {
            if (a[i - 1] < a[i]) isMin = false;
            if (a[i - 1] > a[i]) isMax = false;
        }
 
        if (i < n - 1) {
            if (a[i] > a[i + 1]) isMin = false;
            if (a[i] < a[i + 1]) isMax = false;
        }
 
        if (isMin) local_min.push_back(i + 1);
        if (isMax) local_max.push_back(i + 1);
    }
 
    cout << local_min.size();
    for (int pos : local_min) cout << ' ' << pos;
    cout << '\n';
 
    cout << local_max.size();
    for (int pos : local_max) cout << ' ' << pos;
    cout << '\n';
 
    int min_pos = min_element(a.begin(), a.end()) - a.begin() + 1;
    int max_pos = max_element(a.begin(), a.end()) - a.begin() + 1;
    cout << min_pos << ' ' << max_pos << '\n';
 
    return 0;
}
