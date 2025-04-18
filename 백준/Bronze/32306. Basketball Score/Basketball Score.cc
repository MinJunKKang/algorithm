#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, b, c;
    int d, e, f;
    cin >> a >> b >> c;
    cin >> d >> e >> f;
    int sum_f = a + 2*b + 3*c;
    int sum_s = d + 2*e + 3*f;

    if (sum_f == sum_s) cout << 0;
    else if (sum_f > sum_s) cout << 1;
    else cout << 2;

    return 0;
}