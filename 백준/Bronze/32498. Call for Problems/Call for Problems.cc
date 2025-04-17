#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int result = 0;
    while (n--) {
        int d;
        cin >> d;

        if (d % 2 != 0)
            result++;
    }

    cout << result;
    return 0;
}