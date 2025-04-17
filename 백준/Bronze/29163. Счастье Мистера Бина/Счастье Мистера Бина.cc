#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    int o = 0, e = 0;
    while (n--) {
        int a;
        cin >> a;
        if (a % 2 == 0) e++;
        else o++;
    }

    if (e>o) cout << "Happy";
    else cout << "Sad";

    return 0;
}