#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>

using namespace std;
int arr[101][101]; //1 뱀, 2 사과
int N, K, L;   //보드 크기, 사과 수, 회전 횟수
int ans = 0;  //경과 시간
int dir_idx = 1;   //방향: 상, 우, 하, 좌
int dx[4] = {0, 1, 0, -1}; //상우하좌 방향의 x 좌표 변화량
int dy[4] = {-1, 0, 1, 0}; //상우하좌 방향의 y 좌표 변화량

//사과 위치와 회전 명령을 입력받는 함수
void initializeGame(int& N, int& K, int& L, queue<pair<int, char>>& time) {
    cin >> N >> K;
    for (int i = 0; i < K; i++) {
        int row, col;
        cin >> row >> col;
        arr[row][col] = 2; //사과 위치 표시
    }

    cin >> L;
    for (int i = 0; i < L; i++) {
        int X;
        char C;
        cin >> X >> C;
        time.push({X, C}); //회전 시간과 방향 입력
    }
}

//게임 진행을 관리하는 함수
bool isGameOver(deque<pair<int, int>>& snake) {
    int nRow = snake.back().first + dy[dir_idx];
    int nCol = snake.back().second + dx[dir_idx];

    //벽이나 뱀 몸에 부딪히면 게임 종료
    if (nRow <= 0 || nRow > N || nCol <= 0 || nCol > N || arr[nRow][nCol] == 1)
        return true;
    return false;
}

//뱀이 이동한 후 사과나 빈 칸 처리하는 함수
void moveSnake(deque<pair<int, int>>& snake) {
    int nRow = snake.back().first + dy[dir_idx];
    int nCol = snake.back().second + dx[dir_idx];

    if (arr[nRow][nCol] != 2) {  //사과가 없다면
        arr[snake.front().first][snake.front().second] = 0; //뱀 머리 이동
        snake.pop_front(); // 꼬리 제거
    }

    arr[nRow][nCol] = 1; //새로운 위치에 뱀 몸통 표시
    snake.push_back({nRow, nCol}); //새로운 위치로 뱀 머리 이동
}

//회전 명령을 처리하는 함수
void handleRotation(queue<pair<int, char>>& time) {
    if (!time.empty() && ans == time.front().first) {
        char ch = time.front().second;
        if (ch == 'D') //오른쪽 회전
            dir_idx = (dir_idx + 1) % 4;
        else //왼쪽 회전
            dir_idx = (dir_idx - 1 + 4) % 4;
        time.pop(); //회전 명령 처리 완료
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    queue<pair<int, char>> time; //회전 명령 큐
    initializeGame(N, K, L, time); //게임 초기화

    arr[1][1] = 1; //뱀 초기 위치
    deque<pair<int, int>> snake; //뱀의 위치를 저장하는 덱
    snake.push_back({1, 1}); //뱀 시작 위치 추가

    while (true) {
        ans++; //경과 시간 증가

        if (isGameOver(snake)) //게임 종료 조건
            break;

        moveSnake(snake); //뱀 이동

        handleRotation(time); //회전 처리
    }

    cout << ans << '\n';
    return 0;
}
