#include <iostream>
#include <vector>

using namespace std;

int binary_search(vector<int> &dp, int target) {
    int lft = 0, rgt = dp.size() - 1;
    int ans = rgt + 1;

    while (lft <= rgt) {
        int mid = (lft + rgt) / 2;
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
    int n;
    cin >> n;

    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];

    vector<int> dp;

    for (int i = 0; i < n; i++) {
        int pos = binary_search(dp, v[i]);
        if (pos == dp.size()) dp.push_back(v[i]);
        else dp[pos] = v[i];
    }

    cout << n - dp.size();

    return 0;
}