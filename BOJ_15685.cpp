#include <iostream>
#include <vector>
using namespace std;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1, 0};
bool map[102][102] = {false};

//드래곤 커브를 생성하는 함수
void generateDragonCurve(int x, int y, int d, int g) {
    vector<int> seq(1, d);

    //드래곤 커브 방향 생성
    for (int i = 0; i < g; i++) {
        int sz = seq.size();
        for (int j = sz - 1; j >= 0; j--) {
            seq.push_back((seq[j] + 1) % 4);
        }
    }

    //초기 좌표 표시
    map[y][x] = true;

    //드래곤 커브 이동
    for (int v : seq) {
        v = (v + d) % 4;
        y += dy[v];
        x += dx[v];
        map[y][x] = true;
    }
}

//1x1 사각형 개수를 계산하는 함수
int countSquares() {
    int count = 0;

    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) {
                count++;
            }
        }
    }

    return count;
}

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        int x, y, d, g;
        cin >> x >> y >> d >> g;
        generateDragonCurve(x, y, d, g);
    }

    cout << countSquares() << endl;

    return 0;
}
