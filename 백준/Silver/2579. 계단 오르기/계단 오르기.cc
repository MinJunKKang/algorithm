#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> score(N);
    for (int i = 0; i < N; i++) cin >> score[i];

    vector<int> dp(N+1, 0);
    dp[0] = 0;
    dp[1] = score[0];
    dp[2] = dp[1] + score[1];

    for (int i = 2; i < N; i++) {
        dp[i+1] = max(dp[i-1] + score[i], dp[i-2] + score[i-1] + score[i]);
    }

    cout << dp[N];

    return 0;
}