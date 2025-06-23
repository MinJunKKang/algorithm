#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N, H;
    cin >> N >> H;

    vector<int> bottom(H+1, 0);
    vector<int> top(H+1, 0);
    for (int i = 0; i < N; i++) {
        int tmp; cin >> tmp;
        if (i%2 == 0) bottom[tmp]++;
        else top[tmp]++;
    }

    vector<int> botAcc(H);
    vector<int> topAcc(H);

    botAcc[0] = N/2;
    topAcc[H-1] = N/2;
    for (int i = 1; i < H; i++) {
        botAcc[i] = botAcc[i-1] - bottom[i];
        topAcc[H-(i+1)] = topAcc[H-i] - top[i];
    }

    vector<int> result(H);
    for (int i = 0; i < H; i++) {
        result[i] = botAcc[i] + topAcc[i];
    }
    sort(result.begin(), result.end());

    int minCrash = result[0]; int cnt = 0;
    for (int v: result) {
        if (v == minCrash) cnt++;
    }

    cout << minCrash << " " << cnt;

    return 0;
}