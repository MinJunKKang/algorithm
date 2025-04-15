#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c;
    char t;

    int d, e, f;
    cin >> a >> t >> b >> t >> c;
    cin >> d >> t >> e >> t >> f;

    f -= c;
    if (f < 0) {
        f += 60;
        b += 1;
    }

    e -= b;
    if (e < 0) {
        e += 60;
        a += 1;
    }

    d -= a;
    if (d < 0) {
        d+= 24;
    }

    cout << d * 3600 + e * 60 + f;
    return 0;
}