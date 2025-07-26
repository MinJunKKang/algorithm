#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    vector<int> pos_num;
    vector<int> neg_num;
    int zero_cnt = 0;
    int one_cnt = 0;

    while (N--) {
        int tmp; cin >> tmp;
        if (tmp > 1) pos_num.push_back(tmp);
        else if (tmp < 0) neg_num.push_back(tmp);
        else if (tmp == 0) zero_cnt++;
        else one_cnt++;
    }

    int sum = one_cnt;
    sort(neg_num.begin(), neg_num.end()); sort(pos_num.begin(), pos_num.end());

    int neg_size = neg_num.size(), pos_size = pos_num.size();

    for (int i = pos_size - 1; i >= 0; i -= 2) {
        if (i == 0) { sum += pos_num[i]; }
        else { sum += (pos_num[i] * pos_num[i-1]); }
    }

    for (int i = 0; i < neg_size; i += 2) {
        if (i == neg_size - 1) {
            if (zero_cnt != 0) continue;
            sum += neg_num[i];
        } else {
            sum += (neg_num[i] * neg_num[i + 1]);
        }
    }

    cout << sum;

    return 0;
}