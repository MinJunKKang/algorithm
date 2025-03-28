#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int L, C;
vector<char> alphabet;

bool isVowel(char i) {
    return i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u';
}


void dfs(int idx, string comb) {
    if (comb.size() == L) {
        int vowel = 0, not_vowel = 0;
        for (char c : comb) {
            if (isVowel(c)) vowel++;
            else not_vowel++;
        }

        if (vowel >= 1 && not_vowel >= 2) {
            cout << comb << "\n";
            return;
        }
    }

    for (int i = idx; i < C; i++) {
        dfs(i+1, comb+alphabet[i]);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> L >> C;

    alphabet.resize(C);

    for (int i = 0; i < C; i++) {
        cin >> alphabet[i];
    }

    sort(alphabet.begin(), alphabet.end());
    dfs(0, "");

    return 0;
}