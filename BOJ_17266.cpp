#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;
const int INF = INT_MAX;

int calculateMinRadius(int roadLength, int shelterCount, int shelters[]) {
    int minRadius = INF;  //최소 반지름을 무한대 값으로 초기화
    int left = 0, right = 100000;  //이진 탐색 범위 설정 (반지름)

    while (left <= right) {
        int radius = (left + right) / 2;  // 중간값(반지름) 계산
        bool canCover = true;  //모든 구간을 커버할 수 있는지 확인하는 플래그

        //첫 번째 시작 지점을 커버할 수 있는지 확인
        if (shelters[0] > radius) canCover = false;

        //반지름 내에서 커버 가능한지 확인
        for (int i = 0; i < shelterCount - 1; i++) {
            if (shelters[i + 1] - shelters[i] > radius * 2) {
                canCover = false;
                break;
            }
        }

        //도로의 끝 지점을 커버할 수 있는지 확인
        if (roadLength - shelters[shelterCount - 1] > radius) canCover = false;

        // 모든 지점이 커버되지 않으면, 반지름을 늘려 탐색 범위를 오른쪽으로 조정
        if (!canCover) {
            left = radius + 1;
        } else {
            //모든 지점이 커버될 경우, 최소 반지름 갱신 후 탐색 범위를 왼쪽으로 조정
            minRadius = min(minRadius, radius);
            right = radius - 1;
        }
    }
    return minRadius;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);
    int roadLength, shelterCount;
    cin >> roadLength >> shelterCount;
    int shelters[shelterCount];
    for (int i = 0; i < shelterCount; i++) cin >> shelters[i];

    //최소 반지름을 계산하고 결과 출력
    int minRadius = calculateMinRadius(roadLength, shelterCount, shelters);
    cout << minRadius;

    return 0;
}
