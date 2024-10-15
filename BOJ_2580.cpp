#include <iostream>
#include <vector>
using namespace std;

int sudokuBoard[10][10];  //스도쿠 판
vector<pair<int, int>> emptyCells;  //빈 칸(0)의 좌표들
int emptyCellCount = 0; //빈 칸의 개수
bool isSolved = false;  //스도쿠가 해결되었는지 여부

bool canPlaceNumber(int row, int col, int num) {
    //가로줄, 세로줄 확인
    for (int i = 1; i <= 9; i++) {
        if (sudokuBoard[row][i] == num || sudokuBoard[i][col] == num) {
            return false;
        }
    }

    //확인
    int boxRowStart = (row - 1) / 3 * 3 + 1;
    int boxColStart = (col - 1) / 3 * 3 + 1;
    for (int i = boxRowStart; i < boxRowStart + 3; i++) {
        for (int j = boxColStart; j < boxColStart + 3; j++) {
            if (sudokuBoard[i][j] == num) {
                return false;
            }
        }
    }

    return true;
}

void solveSudoku(int emptyCellIndex) {
    if (isSolved) return;  //이미 스도쿠가 해결되었으면 종료
    if (emptyCellIndex == emptyCellCount) {  //모든 빈 칸을 채운 경우
        //스도쿠 결과 출력
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                cout << sudokuBoard[i][j] << ' ';
            }
            cout << '\n';
        }
        isSolved = true;  //해결 완료
        return;
    }

    int row = emptyCells[emptyCellIndex].first;
    int col = emptyCells[emptyCellIndex].second;

    for (int num = 1; num <= 9; num++) {
        if (canPlaceNumber(row, col, num)) {
            sudokuBoard[row][col] = num;
            solveSudoku(emptyCellIndex + 1);  //다음 빈 칸으로 이동
            sudokuBoard[row][col] = 0;  //상태 복구 (백트래킹)
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            cin >> sudokuBoard[i][j];
            if (sudokuBoard[i][j] == 0) {
                emptyCells.push_back({ i, j });
                emptyCellCount++;
            }
        }
    }

    solveSudoku(0);

    return 0;
}
