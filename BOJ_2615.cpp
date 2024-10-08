#include <iostream>
#define MAX 19 //보드의 크기를 19로 정의 (19x19 바둑판)
using namespace std;

char board[MAX][MAX]; //바둑판을 저장할 2차원 배열
int directions[4][2] = { {0,1}, {1,0}, {1,1}, {-1,1} }; //4가지 방향: 오른쪽, 아래, 대각선 오른쪽 아래, 대각선 왼쪽 아래
bool visited[MAX][MAX][4][2]; //방문 기록 배열 [행][열][방향][플레이어(1=흑, 2=백)]

// 입력된 바둑판 정보를 읽어오는 함수
void readBoard() {
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            cin >> board[i][j]; //바둑판 상태를 입력 받음 (0: 빈 칸, 1: 흑돌, 2: 백돌)
        }
    }
}

//좌표가 보드 범위 내에 있는지 확인하는 함수
bool isOutOfBounds(int row, int col) {
    return row < 0 || row >= MAX || col < 0 || col >= MAX;
}

//깊이 우선 탐색 (DFS) 함수
//인자로 현재 좌표 (row, col), 탐색 방향 (direction), 돌의 색 (color), 현재까지 연속된 돌의 개수 (count)를 받음
char performDFS(int row, int col, int direction, char color, int count) {
    //해당 좌표와 방향에 대해 이미 탐색했음을 표시
    visited[row][col][direction][color - '1'] = true;

    //다음 탐색할 좌표 계산
    int nextRow = row + directions[direction][0];
    int nextCol = col + directions[direction][1];

    //보드 범위를 벗어났거나 다음 좌표의 돌이 현재 색과 다르면 탐색 종료
    if (isOutOfBounds(nextRow, nextCol) || board[nextRow][nextCol] != color) {
        //5개의 돌이 연속되었으면 해당 색을 반환, 그렇지 않으면 '0' 반환
        return (count == 5) ? color : '0';
    }

    //다음 좌표에 대해 DFS 계속 수행
    return performDFS(nextRow, nextCol, direction, color, count + 1);
}

//승자를 찾는 함수
//승리한 돌의 좌표를 반환하기 위해 winnerRow, winnerCol 참조 변수를 받음
char getWinner(int& winnerRow, int& winnerCol) {
    //보드의 각 좌표를 순회
    for (int col = 0; col < MAX; col++) {
        for (int row = 0; row < MAX; row++) {
            //현재 좌표에 돌이 있을 때만 탐색 (빈 칸인 '0'은 무시)
            if (board[row][col] != '0') {
                //4방향으로 DFS를 수행
                for (int direction = 0; direction < 4; direction++) {
                    //이미 탐색된 경로라면 건너뛴다
                    if (visited[row][col][direction][board[row][col] - '1']) continue;

                    //해당 좌표에서 DFS 수행, 연속된 5개의 돌이 있으면 승자를 반환
                    if (performDFS(row, col, direction, board[row][col], 1) != '0') {
                        winnerRow = row + 1; //승리 돌의 행 번호 (1-based)
                        winnerCol = col + 1; //승리 돌의 열 번호 (1-based)
                        return board[row][col]; //승리한 돌의 색 반환 (1: 흑돌, 2: 백돌)
                    }
                }
            }
        }
    }
    //승자가 없으면
    return '0';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    readBoard(); //입력

    int winnerRow = 0, winnerCol = 0; //승리한 돌의 좌표를 저장할 변수
    char winner = getWinner(winnerRow, winnerCol); //승자 탐색

    //승자가 있으면 승자의 색과 좌표 출력, 없으면 0 출력
    if (winner != '0') {
        cout << winner << '\n' << winnerRow << ' ' << winnerCol; //승리한 색과 좌표 출력
    } else {
        cout << 0; //승자가 없으면 0 출력
    }

    return 0;
}
