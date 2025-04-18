#include <iostream>
#include <vector>
#include <algorithm>
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll M, N;
    cin >> M >> N;

    vector<ll> L(N);
    for (int i = 0; i < N; i++) cin >> L[i];
    sort(L.begin(), L.end());

    ll opt_length = 0;
    ll left = 1, right = L[N-1];
    while (left <= right) {
        ll mid = left + (right-left)/2;
        ll cnt = 0;

        for (int i = 0; i < N; i++) {
            cnt += (L[i] / mid);
        }
        if (cnt >= M) {
            left = mid + 1;
            opt_length = mid;
        }
        else right = mid - 1;
    }

    cout << opt_length;

    return 0;
}