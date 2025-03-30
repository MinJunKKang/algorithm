#include <iostream>
#define INF 1e9

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int a[7];
        int result = 0;
        int min_val = INF;
        for (int i = 0; i < 7; i++) {
            cin >> a[i];
            if (a[i] % 2 == 0) {
                result += a[i];
                min_val = min(min_val, a[i]);
            }
        }

        cout << result << " " << min_val << '\n';
    }

    return 0;
}