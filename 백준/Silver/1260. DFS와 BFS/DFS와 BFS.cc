#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[1001];
bool visited[1001] = {0, };
void dfs(int v) {
    cout << v << " ";
    visited[v] = true;
    for( int i = 0; i < a[v].size(); ++i ) {
        int next = a[v][i];
        if( visited[next] == false ) {
            dfs(next);
        }
    }
}

void bfs(int v) {
    queue<int> q;
    visited[v] = true;

    q.push(v);

    while( !q.empty() ) {
        int node = q.front();

        q.pop();
        cout << node << " ";
        for( int i = 0; i < a[node].size(); ++i ) {
            int next = a[node][i];
            if( visited[next] == false ) {
                visited[next] = true;
                q.push(next);
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;

    int ltmp, rtmp;
    while(M--) {
        cin >> ltmp >> rtmp;
        a[ltmp].push_back(rtmp);
        a[rtmp].push_back(ltmp);
    }

    for( int i = 1; i <= N; ++i ) sort(a[i].begin(), a[i].end());

    dfs(V);
    cout << '\n';
    for( int i = 1; i < 1001; ++i ) visited[i] = 0;
    bfs(V);

    return 0;
}
