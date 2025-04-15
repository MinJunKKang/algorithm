#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    int igwa_min = 101;
    int result = 0;
    for (int i = 0; i < 4; i++) {
        int n;
        cin >> n;
        result += n;
        igwa_min = min(igwa_min, n);
    }

    int mungwa_max = 0;
    for (int i = 0; i < 2; i++) {
        int n;
        cin >> n;
        mungwa_max = max(mungwa_max, n);
    }

    result = result - igwa_min + mungwa_max;
    
    cout << result;
    return 0;
}