#include <iostream>
#include <valarray>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T;
    cin >> T;

    while (T--) {
        int ans = 0;

        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        int n; cin >> n;

        vector<int> cx(n);
        vector<int> cy(n);
        vector<int> cz(n);

        for (int i = 0; i < n; i++) cin >> cx[i] >> cy[i] >> cz[i];

        for (int i = 0; i < n; i++) {
            int cnt = 0;
            double dist = sqrt(pow(x1 - cx[i], 2) + pow(y1 - cy[i] , 2));
            if (dist < cz[i]) cnt++;
            dist = sqrt(pow(x2 - cx[i], 2) + pow(y2 - cy[i] , 2));
            if (dist < cz[i]) cnt++;

            if (cnt == 1) ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}