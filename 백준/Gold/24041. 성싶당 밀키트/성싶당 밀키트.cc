#include <iostream>
#include <vector>
#include <algorithm>
#define LNF 2e9
typedef long long ll;


using namespace std;

int N, G, K;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> G >> K;

    vector<vector<int>> mealkit(N, vector<int>(3));

    int un_count = 0;
    for (int i = 0; i < N; i++) {
        cin >> mealkit[i][0] >> mealkit[i][1] >> mealkit[i][2];
        if (mealkit[i][2] == 1) un_count++;
    }

    ll max_day = 0;
    ll left = 0, right = LNF;
    while (left <= right) {
        ll mid = left + (right - left) / 2;
        ll sum = 0;

        if (K == 0 || un_count == 0) {
            for (int i = 0; i < N; i++) {
                ll cond = mid - mealkit[i][1];

                ll tmp  = 1LL * mealkit[i][0] * (cond > 0 ? cond : 1);
                sum += tmp;
            }
        }
        else {
            vector<ll> v;
            for (int i = 0; i < N; i++) {
                ll cond = mid - mealkit[i][1];
                if (mealkit[i][2] == 0) {
                    ll tmp  = 1LL * mealkit[i][0] * (cond > 0 ? cond : 1);
                    sum += tmp;
                } else {
                    ll tmp  = 1LL * mealkit[i][0] * (cond > 0 ? cond : 1);
                    v.push_back(tmp);
                }
            }
            sort(v.begin(), v.end());
            ll v_size = v.size();
            for (int i = 0; i < int(v_size - K); ++i)
                sum += v[i];
        }

        if (sum <= G) {
            max_day = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << max_day;

    return 0;
}