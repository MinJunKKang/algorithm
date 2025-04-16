#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string j;
    string d;
    cin >> j;
    cin >> d;

    if (d.size() <= j.size()) cout << "go";
    else cout << "no";

    return 0;
}