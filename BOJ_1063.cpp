#include <iostream>
#include <string>
using namespace std;

//체스판 좌표를 계산하는 함수
bool isValidMove(int x, int y) {
    return x >= 0 && x < 8 && y >= 0 && y < 8;  //체스판 범위 확인 (0~7)
}

//좌표를 체스 보드 형식(A1, B2)으로 변환하는 함수
string posToChess(int x, int y) {
    return string(1, 'A' + y) + to_string(8 - x);
}

//주어진 방향에 따라 이동하는 함수
void move(string move, int &x, int &y) { //에러 이유: 그냥 xy로 입력한다면 move함수내에서만 xy값이 변경되고, 함수 호출 후에는 원래 변수에 반영되지 않는다
    if (move == "R") y += 1; //오른쪽으로 이동
    else if (move == "L") y -= 1;  //왼쪽으로 이동
    else if (move == "B") x += 1;  //아래로 이동
    else if (move == "T") x -= 1;  //위로 이동
    else if (move == "RT") { x -= 1; y += 1; }  //오른쪽 위 대각선
    else if (move == "LT") { x -= 1; y -= 1; }  //왼쪽 위 대각선
    else if (move == "RB") { x += 1; y += 1; }  //오른쪽 아래 대각선
    else if (move == "LB") { x += 1; y -= 1; }  //왼쪽 아래 대각선
}

//킹과 돌의 움직임을 처리하는 함수
void processMove(string moveCommand, int &kx, int &ky, int &rx, int &ry) {
    //킹의 새로운 위치
    int new_kx = kx, new_ky = ky;
    move(moveCommand, new_kx, new_ky);

    //킹이 체스판을 벗어나지 않으면 움직임 처리
    if (isValidMove(new_kx, new_ky)) {
        //만약 킹이 이동한 위치가 돌의 위치와 같다면
        if (new_kx == rx && new_ky == ry) {
            int new_rx = rx, new_ry = ry;
            move(moveCommand, new_rx, new_ry);

            //돌의 새로운 위치가 체스판 안에 있을 경우 돌도 이동
            if (isValidMove(new_rx, new_ry)) {
                rx = new_rx;
                ry = new_ry;
            } else {
                //돌이 체스판 밖으로 나가면 킹도 움직이지 않는다.
                return;
            }
        }
        //돌과 겹치지 않으면 킹만 이동
        kx = new_kx;
        ky = new_ky;
    }
}

//킹과 돌의 초기 위치를 좌표로 변환하는 함수
void initPositions(const string &king, const string &rock, int &kx, int &ky, int &rx, int &ry) {
    kx = '8' - king[1];  //킹의 행  (에러 이유: king[1] - '8')
    ky = king[0] - 'A';  //킹의 열
    rx = '8' - rock[1];  //돌의 행
    ry = rock[0] - 'A';  //돌의 열
}

//킹과 돌의 움직임 명령을 처리하는 함수
void executeMoves(int n, int &kx, int &ky, int &rx, int &ry) {
    for (int i = 0; i < n; i++) {
        string moveCommand;
        cin >> moveCommand;
        processMove(moveCommand, kx, ky, rx, ry);
    }
}


int main() {
    string king, rock;  //킹과 돌의 위치
    int n;  //이동 명령의 개수
    int kx, ky, rx, ry; //킹과 돌의 좌표

    //입력
    cin >> king >> rock >> n;

    //초기 위치 설정
    initPositions(king, rock, kx, ky, rx, ry);

    //움직임 처리
    executeMoves(n, kx, ky, rx, ry);

    //최종 결과 출력
    cout << posToChess(kx, ky) << '\n';
    cout << posToChess(rx, ry) << '\n';

    return 0;
}
