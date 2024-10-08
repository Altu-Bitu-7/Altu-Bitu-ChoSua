#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> e[101];  //인접 리스트를 사용하여 그래프를 저장
bool check[101];     //방문 여부를 저장하는 배열

void bfs(int start, int &cnt) {
    queue<int> q;  //BFS를 위한 큐
    q.push(start); //시작 노드를 큐에 추가
    check[start] = true;  //시작 노드를 방문 처리

    //큐가 빌 때까지 반복
    while (!q.empty()) {
        int cur = q.front(); //큐의 맨 앞 요소를 가져옴
        q.pop();  //큐에서 맨 앞 요소 제거

        //현재 노드와 연결된 모든 노드를 확인
        for (int next : e[cur]) {
            //아직 방문하지 않은 노드인 경우
            if (!check[next]) {
                check[next] = true;  //방문 처리
                q.push(next);        //큐에 추가하여 다음에 탐색할 수 있도록 함
                cnt++;  //방문한 노드의 수 증가
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int cn, pn, from, to, cnt = 0;  //cn: 컴퓨터 수, pn: 연결된 쌍의 수, cnt: 방문한 노드 수
    cin >> cn >> pn;  //컴퓨터 수와 연결된 쌍의 수 입력

    //연결된 컴퓨터 쌍을 그래프에 추가
    for (int i = 0; i < pn; i++) {
        cin >> from >> to;  //두 컴퓨터 간의 연결 입력
        e[from].push_back(to);  //양방향 연결이므로 양쪽에 추가
        e[to].push_back(from);
    }

    bfs(1, cnt);

    cout << cnt;

    return 0;
}
