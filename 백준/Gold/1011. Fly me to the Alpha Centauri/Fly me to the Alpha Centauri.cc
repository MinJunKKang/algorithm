#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;  cin >> T;
    while (T--) {
        long long x, y;  cin >> x >> y;
        long long d = y - x;

        long long k = sqrtl(d);
        if (k * k == d)                      cout << 2 * k - 1 << '\n';
        else if (d <= k * k + k)             cout << 2 * k     << '\n';
        else                                 cout << 2 * k + 1 << '\n';
    }
    return 0;
}