#include <iostream>
#include <vector>
#include <queue>

typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int T;
    cin >> T;

    pair<ll, ll> dp[41];
    dp[0] = {1, 0};
    dp[1] = {0, 1};

    for (int i = 2; i < 41; i++) {
        dp[i].first = dp[i-1].first + dp[i-2].first;
        dp[i].second = dp[i-1].second + dp[i-2].second;
    }

    for (int i = 0; i < T; i++) {
        int N;
        cin >> N;

        cout << dp[N].first << " " << dp[N].second;
        cout << '\n';
    }

    return 0;
}