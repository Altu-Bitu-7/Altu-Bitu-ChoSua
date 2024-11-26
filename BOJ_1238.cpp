#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

struct edge {
    int end, weight;
    edge(int e, int w) : end(e), weight(w) {}
    bool operator<(const edge& e) const { return weight > e.weight; }
};

vector<vector<int>> dijkstra(int n, vector<edge> graph[]) {
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, INT_MAX));
    for (int i = 1; i <= n; i++) {
        priority_queue<edge> pq;
        pq.push(edge(i, 0));
        dist[i][i] = 0;
        while (!pq.empty()) {
            int cur = pq.top().end, w = pq.top().weight; pq.pop();
            if (w > dist[i][cur]) continue;
            for (auto& e : graph[cur]) {
                if (dist[i][e.end] > dist[i][cur] + e.weight) {
                    dist[i][e.end] = dist[i][cur] + e.weight;
                    pq.push(edge(e.end, dist[i][e.end]));
                }
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, m, x; cin >> n >> m >> x;
    vector<edge> graph[1001];
    while (m--) {
        int s, e, w; cin >> s >> e >> w;
        graph[s].push_back(edge(e, w));
    }
    auto dist = dijkstra(n, graph);
    int res = 0;
    for (int i = 1; i <= n; i++) res = max(res, dist[x][i] + dist[i][x]);
    cout << res;
}
