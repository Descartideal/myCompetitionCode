#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define int long long

typedef long long ll;
ll a[100];

signed main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        ll c, k;
        cin >> n >> c >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a, &a[n]);

        for (int i = 0; i < n; i++) {
            int del = c - a[i];
            if (del < 0) break;
            if (del > 0) {
                if (k >= del) {
                    k -= del;
                    a[i] += del;
                }
                else {
                    a[i] += k;
                    k = 0;
                }
            }
            c += a[i];
        }
        cout << c << '\n';
    }

    return 0;
}