#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;
    vector<ll> dp(101, 0);
    dp[1] = 1; dp[2] = 1; dp[3] = 1; dp[4] = 2; dp[5] = 2;

    for (int i = 6; i <= 100; i++) {
        dp[i] = dp[i-1] + dp[i-5];
    }

    while (T--) {
        int N;
        cin >> N;

        cout << dp[N] << '\n';
    }

    return 0;
}