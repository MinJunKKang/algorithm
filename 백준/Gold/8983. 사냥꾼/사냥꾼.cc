#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

int M, N;
ll L;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> M >> N >> L;

    vector<int> shoot(M);
    for (int i = 0; i < M; i++) cin >> shoot[i];
    sort(shoot.begin(), shoot.end());

    int cnt = 0;
    for (int i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;

        if (y > L) continue;

        ll left = x - (L - y);
        ll right = x + (L - y);

        auto it = lower_bound(shoot.begin(), shoot.end(), left);
        if (it != shoot.end() && *it <= right) cnt++;
    }

    cout << cnt;

    return 0;
}