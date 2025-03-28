#include <iostream>
#include <queue>
#include <vector>
using namespace std;

typedef long long ll;
const ll INF = 1e15;

int N, M;
vector<pair<int, int>> adj[100001];
int move_able[100001];
bool visited[100001];

void dijkstra() {
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
    vector<ll> dist(N, INF);
    
    dist[0] = 0;
    pq.push({0, 0});
    
    while (!pq.empty()) {
        auto [cur_cost, cur] = pq.top();
        pq.pop();

        if (visited[cur]) continue;
        visited[cur] = true;
        
        if (cur == N - 1) {
            cout << cur_cost;
            return;
        }
        
        for (auto [next, t] : adj[cur]) {
            if (move_able[next] == 1 && next != N - 1) continue;
            
            ll new_cost = cur_cost + t;
            if (new_cost < dist[next]) {
                dist[next] = new_cost;
                pq.push({new_cost, next});
            }
        }
    }
    
    cout << -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++) {
        cin >> move_able[i];
    }
    
    for (int i = 0; i < M; i++) {
        int a, b, t;
        cin >> a >> b >> t;
        adj[a].push_back({b, t});
        adj[b].push_back({a, t});
    }
    
    dijkstra();
    
    return 0;
}
