#include <bits/stdc++.h>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int>> right;
 
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
 
        left.push(x);
 
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }
 
        if (!right.empty() && left.top() > right.top()) {
            int a = left.top(); left.pop();
            int b = right.top(); right.pop();
            left.push(b);
            right.push(a);
        }
 
        cout << left.top() << '\n';
    }
 
    return 0;
}
