#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        int cnt = 0;

        for (int a = 1; a < n - 1; a++) {
            for (int b = a+1; b < n; b++) {
                if (((a * a + b* b + m) % (a * b)) == 0)
                    cnt++;
            }
        }
        cout << cnt << '\n';
    }

    return 0;
}