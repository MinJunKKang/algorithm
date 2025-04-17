#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int year = 2024 + (8 + 7 *(N-1)) / 12;
    int month = (8 + 7 *(N-1)) % 12;
    if (month == 0) {
        month = 12;
        year--;
    }

    cout << year << " " << month;
    
    return 0;
}