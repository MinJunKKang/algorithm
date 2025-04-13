#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int L;
    cin >> L;

    vector<char> arr(L);

    for (int i = 0; i < L; i++) cin >> arr[i];

    ll H = 0;
    int r = 31, M = 1234567891;

    for (int i = 0; i < L; i++) {
        int tmp = (arr[i] - 'a' + 1);
        ll k = 1;
        for (int j = 0; j < i; j++) {
            k = (k * r) % M;
        }

        H = (H + tmp * k) % M;
    }

    cout << H;

    return 0;
}