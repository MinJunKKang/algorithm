#include <iostream>
#include <vector>
#define INF 1000000000
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<ll> spend_time(N);
    ll min_time = INF;
    for (int i = 0; i < N; i++) {
        cin >> spend_time[i];
        min_time = min(min_time, spend_time[i]);
    }

    ll max_time = min_time * M;

    ll left = 0;

    ll minn_time;
    while (left <= max_time) {
        ll mid = left + (max_time - left) / 2;
        ll cnt = 0;
        for (int i = 0; i < N; i++) {
            cnt += (mid / spend_time[i]);
        }
        if (cnt >= M) {
            max_time = mid - 1;
            minn_time = mid;
        }
        else left = mid + 1;
    }

    cout << minn_time;

    return 0;
}