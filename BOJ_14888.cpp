#include <iostream>
#include <vector>
#include <algorithm>
#define MAX 1000000000
using namespace std;

int minimum = MAX, maximum = -MAX;
vector<int> num; //숫자들
int oper[4]; //덧셈, 뺄셈, 곱셈, 나눗셈의 개수

void backtrack(int idx, int current) {
    if (idx == num.size()) {  //숫자를 모두 사용한 경우
        minimum = min(minimum, current);
        maximum = max(maximum, current);
        return;
    }

    for (int i = 0; i < 4; i++) { //4가지 연산자에 대해 가능한 연산을 수행
        if (oper[i] > 0) {  //연산자가 남아있는 경우에만 사용
            oper[i]--;  //해당 연산자 하나 사용

            if (i == 0) //덧셈
                backtrack(idx + 1, current + num[idx]);
            else if (i == 1) //뺄셈
                backtrack(idx + 1, current - num[idx]);
            else if (i == 2) //곱셈
                backtrack(idx + 1, current * num[idx]);
            else if (i == 3) //나눗셈
                backtrack(idx + 1, current / num[idx]);

            oper[i]++;  //사용한 연산자 복구 (백트래킹)
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n;

    num.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < 4; i++) {
        cin >> oper[i];
    }

    //백트래킹 탐색 시작 (첫 번째 숫자를 current로 설정)
    backtrack(1, num[0]);
    cout << maximum << '\n' << minimum << '\n';

    return 0;
}
