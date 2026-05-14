#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int k = (n + 1) / 2;
    int m = (k + 1) / 2;

    for (int i = 0; i < n; ++i) {
        if (1 <= a[i] && a[i] <= k) a[i] = m;
    }

    for (int i = 0; i < n; ++i) {
        cout << a[i] << (i + 1 == n ? '\n' : ' ');
    }
    return 0;
}
