#include <iostream>
#include <string>
using namespace std;

//비트 연산을 수행하는 함수들
void add(int &BIT, int val) {
    BIT |= (1 << val); //val번째 비트를 1로 설정
}

void remove(int &BIT, int val) {
    BIT &= ~(1 << val); //val번째 비트를 0으로 설정
}

bool check(const int BIT, int val) {
    return BIT & (1 << val); //val번째 비트가 1인지 0인지 반환
}

void toggle(int &BIT, int val) {
    BIT ^= (1 << val); //val번째 비트를 반전
}

void all(int &BIT) {
    BIT = (1 << 21) - 1; //모든 비트를 1로 설정 (1~20번 비트)
}

void empty(int &BIT) {
    BIT = 0; //모든 비트를 0으로 설정
}

int main() {
    ios_base::sync_with_stdio(false);  //시간초과 대비
    cin.tie(NULL);
    cout.tie(NULL);

    int m;
    cin >> m;

    string order;
    int val, BIT = 0; //BIT를 반드시 0으로 초기화 해준다.

    while (m--) {
        cin >> order;
        if (order == "add") {
            cin >> val;
            add(BIT, val);
        } else if (order == "remove") {
            cin >> val;
            remove(BIT, val);
        } else if (order == "check") {
            cin >> val;
            cout << (check(BIT, val) ? 1 : 0) << '\n';
        } else if (order == "toggle") {
            cin >> val;
            toggle(BIT, val);
        } else if (order == "all") {
            all(BIT);
        } else if (order == "empty") {
            empty(BIT);
        }
    }

    return 0;
}