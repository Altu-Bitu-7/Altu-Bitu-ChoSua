#include <iostream>
#include <vector>

using namespace std;
int N, R, Q;  //N: 노드의 수, R: 루트 노드, Q: 질의 수
vector<int> queries;   //질의들을 저장하는 벡터
vector<int> adj[100001];   //각 노드의 인접 리스트 (트리 구조)
bool visited[100001];   //방문 여부를 체크하는 배열
int subtree_size[100001];  //각 노드의 서브트리 크기를 저장하는 배열

//서브트리 크기를 계산하는 함수
int calculateSubtreeSize(int node) {
    visited[node] = true;
    subtree_size[node] = 1; //자기 자신을 포함한 크기

    //인접한 노드들에 대해 DFS
    for (int i = 0; i < adj[node].size(); i++) {
        int next_node = adj[node][i];
        if (visited[next_node]) continue; //이미 방문한 노드는 건너뛰기
        subtree_size[node] += calculateSubtreeSize(next_node);
    }

    return subtree_size[node];
}

//입력
void processInput() {
    int u, v, query_node;
    cin >> N >> R >> Q;

    //트리의 간선 입력 받기
    for (int i = 0; i < N - 1; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    //질의 입력 받기
    for (int i = 0; i < Q; i++) {
        cin >> query_node;
        queries.push_back(query_node);
    }

    //초기 서브트리 크기 설정 (1로 설정)
    for (int i = 0; i <= N; i++) {
        subtree_size[i] = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    processInput();

    //루트 노드부터 DFS로 서브트리 크기 계산
    calculateSubtreeSize(R);

    //질의에 대한 결과 출력
    for (int query_node : queries) {
        cout << subtree_size[query_node] << "\n";
    }

    return 0;
}
