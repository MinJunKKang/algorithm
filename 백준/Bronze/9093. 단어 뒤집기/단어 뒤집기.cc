#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main() {
    int T;
    cin >> T;
    cin.ignore();

    while (T--) {
        string line;
        getline(cin, line);

        istringstream iss(line);
        string word;
        while (iss >> word) {
            for (int i = word.size()-1; i >= 0; i--) {
                cout << word[i];
            }
            cout << " ";
        }
        cout << '\n';
    }

    return 0;
}