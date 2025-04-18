#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x;
    cin >> x;

    int cnt = 0;
    for (int i = 1; i <= x; i++) {
        if (i % 2 == 1) cnt += 3;
        else cnt -= 2;
    }

    cout << cnt;

    return 0;
}