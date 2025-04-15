#include <iostream>

using namespace std;

int main() {
    string a = "SciComLove";
    int N;
    cin >> N;
    if (N % 2 == 1) {
        for (int i = a.size() - 1; i >= 0; i--) cout << a[i];
    } else cout << a;

    return 0;
}