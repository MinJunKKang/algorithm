#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    vector<int> money(n);
    for (int i = 0; i < n; i++)
        cin >> money[i];


    long long cur_sum = 0;
    for (int i = 0; i < m; i++)
        cur_sum += money[i];

    long long max_sum = cur_sum;
    for (int i = m; i < n; i++) {
        cur_sum = cur_sum + money[i] - money[i-m];
        max_sum = max(cur_sum, max_sum);
    }

    cout << max_sum;

    return 0;
}