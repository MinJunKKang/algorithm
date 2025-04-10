#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, C;
vector<int> home;

bool isPossible(int x) {
    int lft = home[0];
    int cnt = 1;
    for (int i: home) {
        if ((i - lft) >= x) {
            cnt++;
            lft = i;
        }
    }

    return (cnt >= C);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> C;

    home.resize(N);
    for (int i = 0; i < N; i++) cin >> home[i];
    sort(home.begin(), home.end());

    int left = 1;
    int right = home[N-1] - home[0];

    int valid_result;
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (isPossible(mid)) {
            valid_result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << valid_result;

    return 0;
}