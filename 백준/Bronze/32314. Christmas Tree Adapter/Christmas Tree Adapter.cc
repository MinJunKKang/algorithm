#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a, w, v;
    cin >> a;
    cin >> w >> v;
    w /= v;
    if (a <= w) cout << 1;
    else cout << 0;

    return 0;
}