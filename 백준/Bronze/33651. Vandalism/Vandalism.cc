#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S = "UAPC";

    string s;
    cin >> s;

    bool u = false;
    bool a = false;
    bool p = false;
    bool c = false;

    for (char i: s) {
        if (i == 'U') u = true;
        else if (i == 'A') a = true;
        else if (i == 'P') p = true;
        else if (i == 'C') c = true;
    }

    if (!u) cout << 'U';
    if (!a) cout << 'A';
    if (!p) cout << 'P';
    if (!c) cout << 'C';

    return 0;

    return 0;
}