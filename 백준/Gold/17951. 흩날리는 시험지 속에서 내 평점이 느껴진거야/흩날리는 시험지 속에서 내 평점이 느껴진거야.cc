#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
vector<int> exam;

bool isPossible(int x) {
    int cnt = 0;
    int sum = 0;
    for (int i: exam) {
        sum += i;
        if (sum >= x) {
            cnt++;
            sum = 0;
        }
    }

    return cnt >= K;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    exam.resize(N);
    int max_sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> exam[i];
        max_sum += exam[i];
    }

    int left = 0, right = max_sum;

    int valid_score;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (isPossible(mid)) {
            valid_score = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << valid_score;

    return 0;
}