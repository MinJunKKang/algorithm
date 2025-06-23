#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);

    int N, H;
    cin >> N >> H;

    int hN = N / 2;

    vector<int> bottom(hN);
    vector<int> top(hN);

    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        if (i%2 == 0) {
            bottom[i/2] = tmp;
        } else {
            top[i/2] = tmp;
        }
    }

    sort(top.begin(), top.end());
    sort(bottom.begin(), bottom.end());

    vector<int> result(H);

    for (int i = 1; i <=H ; i++) {
        int bCrash = bottom.end() - lower_bound(bottom.begin(), bottom.end(), i);
        int need = H - i + 1;
        int tCrash = top.end() - lower_bound(top.begin(), top.end(), need);
        result[i-1] = bCrash + tCrash;
    }

    sort(result.begin(), result.end());

    int minCrash = result[0];
    int cnt = 0;
    for (int v : result)
        if (v == minCrash) ++cnt;
        else break;

    cout << result[0] << " " << cnt;

    return 0;
}