#include <iostream>
#include <vector>

using namespace std;

int N, M;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    vector<int> money(N);
    int max_money = 0;
    for (int i = 0 ; i < N; i++) {
        cin >> money[i];
        max_money = max(max_money, money[i]);
    }

    cin >> M;

    int left = 1, right = M;
    int opt_result;
    while (left <= right) {
        long long result = 0;
        int mid = left + (right - left) / 2;
        for (int i = 0; i < N; i++) {
            if (money[i] > mid) result += mid;
            else result += money[i];
        }

        if (result <= M) {
            opt_result = mid;
            left = mid + 1;
        } else right = mid - 1;
    }

    if (opt_result > max_money) opt_result = max_money;
    cout << opt_result;

    return 0;
}