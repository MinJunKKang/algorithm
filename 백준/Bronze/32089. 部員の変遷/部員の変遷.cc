#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (true) {
        int N;
        cin >> N;
        if (N == 0) break;

        vector<int> a(N);
        for (int i = 0; i < N; i++) cin >> a[i];

        int sum = a[0] + a[1] + a[2];
        int max_sum = sum;
        for (int i = 3; i < N; i++) {
            sum = sum + a[i] - a[i-3];
            max_sum = max(sum, max_sum);
        }

        cout << max_sum << '\n';
    }

    return 0;
}