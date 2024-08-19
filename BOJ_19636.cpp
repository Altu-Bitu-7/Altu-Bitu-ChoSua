#include <iostream>
#include <cmath> // abs 함수 사용을 위한 헤더 파일
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

    // 다이어트 기간 동안의 변화 계산
    for(int day = 0; day < D; day++) {
        // 기초 대사량 변화를 고려하지 않은 체중 계산 (weight1)
        weight1 += (I - (iBefore + A));

        // 기초 대사량 변화를 고려한 체중 계산 (weight2)
        int dailyConsumption = iAfter + A;
        weight2 += (I - dailyConsumption);

        // 기초 대사량이 역치 이상 변동할 때 iAfter를 업데이트
        if (abs(I - dailyConsumption) > tBefore) {
            iAfter += (I - dailyConsumption) / 2;
        }
    }

    // 첫 번째 출력 라인: weight1 체크
    if (weight1 <= 0) {
        cout << "Danger Diet" << endl;
    } else {
        cout << weight1 << " " << iBefore << endl;
    }

    // 두 번째 출력 라인: weight2와 iAfter 체크
    if (weight2 <= 0 || iAfter <= 0) {
        cout << "Danger Diet" << endl;
    } else {
        // 다이어트 후 기초 대사량과 활동 대사량으로 돌아갔을 때 체중 변화 확인
        int finalWeight = weight2 + (I - (iAfter + A)) * D;
        string result = (finalWeight < weight2) ? "YOYO" : "NO";
        cout << weight2 << " " << iAfter << " " << result << endl;
    }

    return 0;
}
