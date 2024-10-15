#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int totalNumbers, sequenceLength;
vector<int> currentSequence;  //현재까지 선택된 수열
vector<int> availableNumbers; //입력된 숫자들
vector<bool> isUsed;  //각 숫자의 사용 여부를 기록

void backtrack(int depth) {
    if (depth == sequenceLength) { //수열의 길이가 M에 도달했을 때 출력
        for (const int& number : currentSequence) {
            cout << number << ' ';
        }
        cout << "\n";
        return;
    }

    for (int i = 0; i < totalNumbers; i++) {
        //중복된 숫자 방지: 이전 숫자가 동일하고, 그 숫자가 사용되지 않았다면 건너뜀
        if (i >= 1 && availableNumbers[i - 1] == availableNumbers[i] && !isUsed[i - 1]) continue;
        if (!isUsed[i]) { //사용되지 않은 숫자일 경우
            isUsed[i] = true;
            currentSequence[depth] = availableNumbers[i];
            backtrack(depth + 1);  //다음 숫자 선택
            isUsed[i] = false;  //상태 복구 (백트래킹)
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> totalNumbers >> sequenceLength;
    availableNumbers.resize(totalNumbers);
    currentSequence.resize(sequenceLength);
    isUsed.resize(totalNumbers, false); //사용 여부를 초기화

    for (int i = 0; i < totalNumbers; i++) {
        cin >> availableNumbers[i];
    }

    //중복된 숫자 처리를 위해 정렬
    sort(availableNumbers.begin(), availableNumbers.end());
    backtrack(0);

    return 0;
}
