#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K; cin >> N >> K;

    vector<int> vec(N);
    int lo = 1e9, hi = 0;
    for (int &x: vec) {
        cin >> x;
        lo = min(lo, x);
        hi = max(hi, x);
    }

    auto feasible = [&](int T) {
        int bad = 0;
        for (int c: vec) {
            if (c > T) {
                if (++bad == K) return false;
            }
            else bad = 0;
        }
        return true;
    };

    while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (feasible(mid)) hi = mid;
        else lo = mid + 1;
    }

    cout << lo << '\n';

    return 0;
}