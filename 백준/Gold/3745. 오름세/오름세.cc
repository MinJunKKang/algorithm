#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &dp, int target) {
    int lft = 0, rgt = dp.size() - 1;
    int ans = rgt + 1;

    while (lft <= rgt) {
        int mid = lft + (rgt - lft) / 2;
        if (dp[mid] >= target) {
            ans = mid;
            rgt = mid - 1;
        } else {
            lft = mid + 1;
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    int N;
    while (cin >> N) {
        vector<int> dp;

        vector<int> line(N);
        for (int i = 0; i < N; i++) cin >> line[i];

        for (int i = 0; i < N; i++) {
            int pos = binary_search(dp, line[i]);
            if (pos == dp.size()) dp.push_back(line[i]);
            else dp[pos] = line[i];
        }

        cout << dp.size() << '\n';
    }

    return 0;
}