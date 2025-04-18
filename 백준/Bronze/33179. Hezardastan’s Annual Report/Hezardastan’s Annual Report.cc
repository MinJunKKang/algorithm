#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;

        cnt += (k % 2 + k / 2);
    }

    cout << cnt;

    return 0;
}