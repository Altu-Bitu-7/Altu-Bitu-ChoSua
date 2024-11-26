#include <iostream>
#define INF 123456789
using namespace std;

void initializeGraph(int n, int arr[501][501]) {
    fill(&arr[0][0], &arr[500][501], INF);
}

void floydWarshall(int n, int arr[501][501]) {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (arr[i][k] == 1 && arr[k][j] == 1) arr[i][j] = 1;
            }
        }
    }
}

int countReachableNodes(int n, int arr[501][501]) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 1; j <= n; j++) {
            if (arr[i][j] == 1 || arr[j][i] == 1) count++;
        }
        if (count == n - 1) ans++;
    }
    return ans;
}

int main() {
    int n, m, arr[501][501];
    cin >> n >> m;

    initializeGraph(n, arr);

    while (m--) {
        int a, b;
        cin >> a >> b;
        arr[a][b] = 1;
    }

    floydWarshall(n, arr);
    cout << countReachableNodes(n, arr);

    return 0;
}
