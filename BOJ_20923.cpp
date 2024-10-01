#include <iostream>
#include <deque>
using namespace std;

//게임을 진행하는 함수
void playGame(deque<int>& dodo, deque<int>& suyeon, int rounds, string& winner) {
    deque<int> doGround;  //도도의 카드
    deque<int> suGround;  //수연의 카드
    bool isDodoTurn = true;  //도도의 차례 여부
    int cnt = 0;             //게임 진행 횟수 카운트

    while (true) {
        cnt++;  //게임 진행 횟수 증가

        //차례에 따라 카드 내려놓기
        if (isDodoTurn) {
            doGround.push_back(dodo.back());
            dodo.pop_back();
        } else {
            suGround.push_back(suyeon.back());
            suyeon.pop_back();
        }

        //카드가 0개 됐는지 체크
        if (dodo.empty()) {
            winner = "su";  //도도의 카드가 0개면 수연이 승리
            break;
        } else if (suyeon.empty()) {
            winner = "do";  //수연의 카드가 0개면 도도 승리
            break;
        }

        //종 치는 상황 체크
        if (!doGround.empty() && !suGround.empty() && doGround.back() + suGround.back() == 5) {
            while (!doGround.empty()) {
                suyeon.push_front(doGround.front());
                doGround.pop_front();
            }
            while (!suGround.empty()) {
                suyeon.push_front(suGround.front());
                suGround.pop_front();
            }
        }
        else if ((!doGround.empty() && doGround.back() == 5) || (!suGround.empty() && suGround.back() == 5)) {
            while (!suGround.empty()) {
                dodo.push_front(suGround.front());
                suGround.pop_front();
            }
            while (!doGround.empty()) {
                dodo.push_front(doGround.front());
                doGround.pop_front();
            }
        }

        //지정된 라운드 수가 되었을 때
        if (cnt == rounds) {
            int result = dodo.size() - suyeon.size();
            if (result < 0) winner = "su";
            else if (result > 0) winner = "do";
            else winner = "dosu";
            break;
        }

        //차례 변경
        isDodoTurn = !isDodoTurn;
    }
}

int main() {
    int n, m;           //n: 카드 개수, m: 게임 진행 라운드 수
    cin >> n >> m;

    deque<int> dodo(n);  //도도의 카드 덱
    deque<int> suyeon(n); //수연의 카드 덱

    for (int i = 0; i < n; i++) {
        cin >> dodo[i] >> suyeon[i];
    }

    string winner = "";  //승자
    playGame(dodo, suyeon, m, winner);

    cout << winner;
    return 0;
}
