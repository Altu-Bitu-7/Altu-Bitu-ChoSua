#include <iostream>
using namespace std;

//'666'이 포함된 숫자를 찾는 함수
int findNumber(int n) {
    int cnt = 0;  //cnt를 사용해서 "666"이 포함된 숫자의 개수를 찾는다
    for (int i = 666; ; i++) {  //i를 666부터 시작하여 계속 증가시키며, 현재 숫자에서 "666"이 포함되어 있는지 검사 (condition x: 무한반복)
        int tmp = i;
        //현재 숫자에서 '666'이 포함되어 있는지 검사
        while (tmp >= 666) {
            if (tmp % 1000 == 666) {
                cnt++;  //"666"이 포함된 숫자를 찾으면 cnt를 증가시키고
                break;
            }
            tmp /= 10;
        }
        if (n == cnt) {
            return i;  //cnt가 n과 같아지면 해당 숫자를 반환합
        }
    }
}

int main() {
    int n;
    cin >> n;  //입력
    cout << findNumber(n) << '\n';  // 출력
    return 0;
}
