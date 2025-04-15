#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> book(9);
    for (int i = 0; i < 9; i++) {
        cin >> book[i];
        N -= book[i];
    }
    cout << N;
    return 0;
}