#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> x(N);
    for (int &a: x) cin >> a;

    for (int &a: x) a = -a;

    vector<int> dp;

    for (int i = 0; i < N; i++) {
        int pos = lower_bound(dp.begin(), dp.end(), x[i]) - dp.begin();
        if (pos == (int)dp.size()) dp.push_back(x[i]);
        else dp[pos] = x[i];
    }

    cout << N - dp.size();

    return 0;
}