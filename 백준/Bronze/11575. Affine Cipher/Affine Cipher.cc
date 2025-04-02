#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;



    while (T--) {
        int a, b;
        cin >> a >> b;

        string s;
        cin >> s;

        int k = s.size();
        int str[k];
        for (int i = 0; i < s.size(); i++) {
            int tmp = int(s[i] - 'A');
            tmp = (a * tmp + b) % 26;
            str[i] = tmp;
        }

        string affine;
        for (int i = 0; i < s.size(); i++) {
            affine.push_back(char(str[i] + 65));
        }

        cout << affine << '\n';
    }

    return 0;
}