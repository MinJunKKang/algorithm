#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string k;
    cin >> k;

    int result = 0;
    for (int i = 0; i < k.size(); i++) {
        if (k[i] - '0' == 0) result = (result + (k[i-1] - '0') * 10 - (k[i-1] - '0'));
        else result += k[i] - '0';
    }

    cout << result;

    return 0;
}