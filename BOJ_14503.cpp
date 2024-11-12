#include <iostream>
#include <vector>

using namespace std;

const int MAX_SIZE = 52;
int board[MAX_SIZE][MAX_SIZE];
bool cleaned[MAX_SIZE][MAX_SIZE];
int dx[4] = {-1, 0, 1, 0}; //방향 벡터 (북, 동, 남, 서)
int dy[4] = {0, 1, 0, -1}; //방향 벡터 (북, 동, 남, 서)

//로봇이 청소하는 함수
int cleanRoom(int N, int M, int startRow, int startCol, int direction) {
    int cleanedCount = 0;

    while (true) {
        //현재 위치가 청소되지 않았으면 청소
        if (!cleaned[startRow][startCol]) {
            cleaned[startRow][startCol] = true;
            cleanedCount++;
        }

        bool foundUncleaned = false;
        //네 방향을 돌며 청소할 곳 탐색
        for (int i = 0; i < 4; i++) {
            direction = (direction + 3) % 4; //왼쪽으로 회전
            int newRow = startRow + dx[direction];
            int newCol = startCol + dy[direction];

            //왼쪽 방향에 청소하지 않은 공간이 있으면 이동
            if (board[newRow][newCol] == 0 && !cleaned[newRow][newCol]) {
                startRow = newRow;
                startCol = newCol;
                foundUncleaned = true;
                break;
            }
        }

        //청소할 공간이 없을 경우
        if (!foundUncleaned) {
            int backDirection = (direction + 2) % 4; //후진할 방향 계산
            int backRow = startRow + dx[backDirection];
            int backCol = startCol + dy[backDirection];

            //후진할 위치가 벽일 경우 종료
            if (board[backRow][backCol] == 1) break;

            //후진 가능하면 후진
            startRow = backRow;
            startCol = backCol;
        }
    }
    return cleanedCount;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M, startRow, startCol, direction;
    cin >> N >> M >> startRow >> startCol >> direction;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    //청소 시작 및 결과 출력
    cout << cleanRoom(N, M, startRow, startCol, direction) << "\n";

    return 0;
}
