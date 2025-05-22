#include <iostream>
#include <vector>

using namespace std;

char ary[100][100] = {};

int main() {
    vector<string> v;
    int n = 0; int m = 0; int count = 0;
    
    cin >> n >> m;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cin >> ary[i][j];
    }
    for(int i = 0; i < n; i++) {
        string temp = "";
        for(int j = 0; j < m; j++) temp += ary[i][j];
        v.push_back(temp);
    }
    
    int k = v.size();
    for(int i = 0; i < k; i++) {
        int tC = 0;
        int l = v[i].length();
        for(int j = 0; j < l; j++) {
            if(v[i][j] == 'A') tC++;
        }
        if(tC == 1) count++;
    }
    
    if(count == v.size()) cout << "Yes";
    else cout << "No";
    
    return 0;
}