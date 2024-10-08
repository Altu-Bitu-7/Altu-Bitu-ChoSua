#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> person[101];
bool visited[101];

//BFS를 수행하여 촌수를 계산하는 함수
int calculateKinship(int p1, int p2) {
    queue<pair<int, int>> bfs;
    bfs.push({p1, 0});
    visited[p1] = true;

    while (!bfs.empty()) {
        auto [p, cnt] = bfs.front();
        bfs.pop();

        if (p == p2) {
            return cnt;
        }

        for (int next : person[p]) {
            if (!visited[next]) {
                visited[next] = true;
                bfs.push({next, cnt + 1});
            }
        }
    }
    return -1; //촌수를 찾을 수 없을 때
}

int main(void) {
    int N, T, p1, p2, n1, n2;

    cin >> N;            //사람 수
    cin >> p1 >> p2;     //촌수를 계산할 두 사람
    cin >> T;            //관계 수

    for (int i = 0; i < T; i++) {
        cin >> n1 >> n2;
        person[n1].push_back(n2);
        person[n2].push_back(n1);
    }

    int res = calculateKinship(p1, p2);
    cout << res << endl;

    return 0;
}
