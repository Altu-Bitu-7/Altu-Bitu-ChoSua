#include <iostream>
using namespace std;

int main() {
    int wBefore;  // 다이어트 전 체중
    int iBefore;  // 다이어트 전 일일 기초 대사량
    int tBefore;  // 기초 대사량 역치
    cin >> wBefore >> iBefore >> tBefore;

    int D;  // 다이어트 기간
    int I;  // 다이어트 기간 일일 에너지 섭취량
    int A;  // 다이어트 기간 일일 활동 대사량
    cin >> D >> I >> A;

    int weight1 = wBefore;  // 기초 대사량 변화를 고려하지 않은 체중
    int weight2 = wBefore;  // 기초 대사량 변화를 고려한 체중
    int iAfter = iBefore;   // 다이어트 후 일일 기초 대사량

    // 다이어트 기간 동안의 변화를 계산한다
    for(int day = 0; day < D; day++) {
        // 기초 대사량 변화를 고려하지 않은 체중을 계산 계산한다(weight1)
        weight1 += (I - (iBefore + A));

        // 기초 대사량 변화를 고려한 체중을 계산한다 (weight2)
        int dailyConsumption = iAfter + A;
        weight2 += (I - dailyConsumption);

        // 기초 대사량이 역치 이상일 때 iAfter 값을 변경한다
        if (abs(I - dailyConsumption) > tBefore) {
            iAfter += (I - dailyConsumption) / 2;
        }
    }

    // 첫 번째 출력 라인: weight1 체크한다
    if (weight1 <= 0) {
        cout << "Danger Diet" << endl;
    } else {
        cout << weight1 << " " << iBefore << endl;
    }

    // 두 번째 출력 라인: weight2와 iAfter 체크 (Danger Diet가 첫째줄에 출력되면 둘째줄이 출력이 안돼는 오류)
    if (weight2 <= 0 || iAfter <= 0) {
        cout << "Danger Diet" << endl;
    } else {
        // 다이어트 후 기초 대사량과 활동 대사량으로 돌아갔을 때 체중 변화를 확인한다
        int finalWeight = weight2 + (I - (iAfter + A)) * D;
        string result = (finalWeight < weight2) ? "YOYO" : "NO";
        cout << weight2 << " " << iAfter << " " << result << endl;
    }

    return 0;
}
