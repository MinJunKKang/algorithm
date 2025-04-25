#include <iostream>
typedef long long ll;

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int hwa = 0;

    int N;
    cin >> N;


    ll result = 0;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

        if (tmp == 0) hwa--;
        else hwa++;
        result += hwa;
    }

    cout << result;
    return 0;
}