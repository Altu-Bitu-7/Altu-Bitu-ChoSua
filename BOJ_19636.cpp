#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int wBefore, iBefore, tBefore;  // 초기 체중, 초기 기초 대사량, 기초 대사량 역치
    cin >> wBefore >> iBefore >> tBefore;

    int D, I, A;  // 다이어트 기간, 일일 에너지 섭취량, 일일 활동 대사량
    cin >> D >> I >> A;

    int weight1 = wBefore;  // 기초 대사량 변화를 고려하지 않은 체중
    int weight2 = wBefore;  // 기초 대사량 변화를 고려한 체중
    int iAfter = iBefore;   // 다이어트 후 일일 기초 대사량

    // 다이어트 기간 동안의 변화 계산
    for (int day = 0; day < D; day++) {
        // 기초 대사량 변화를 고려하지 않은 체중 계산 (weight1)
        weight1 += I - (iBefore + A);

        // 기초 대사량 변화를 고려한 체중 계산 (weight2)
        weight2 += I - (iAfter + A);

        // 기초 대사량이 역치 이상 변동할 때 iAfter를 업데이트
        if (abs(I - (iAfter + A)) > tBefore) {
            iAfter += ((I - (iAfter + A)) / 2);
        }
    }

    // 첫 번째 출력: weight1이 0 이하인 경우 "Danger Diet"
    if (weight1 <= 0) {
        cout << "Danger Diet" << endl;
    } else {
        cout << weight1 << " " << iBefore << endl;
    }

    // 두 번째 출력: weight2와 iAfter 체크
    if (weight2 <= 0 || iAfter <= 0) {
        cout << "Danger Diet" << endl;
    } else {
        cout << weight2 << " " << iAfter << " ";
        if(iBefore - iAfter > 0) {
            cout << "YOYO";
        } else {
            cout << "NO";
        }
    }
}
