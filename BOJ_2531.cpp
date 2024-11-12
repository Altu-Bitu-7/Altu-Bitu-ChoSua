#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

//연속된 k개의 접시에서 선택 가능한 최대 스시 종류를 계산하는 함수 (쿠폰 스시 포함)
int calculateMaxSushiTypes(const vector<int>& sushiTypes, int numSushiTypes, int consecutivePlates, int couponSushi) {
    vector<int> eatenSushi(numSushiTypes + 1, 0); //각 스시 종류별로 먹은 개수를 저장하는 배열
    int currentTypes = 0; //현재 구간에서 먹은 스시 종류 수

    //초기 구간(처음부터 연속된 'consecutivePlates' 개의 접시)에 대한 스시 종류 수 계산
    for (int i = 0; i < consecutivePlates; i++) {
        if (eatenSushi[sushiTypes[i]] == 0) currentTypes++; //새 종류가 등장하면 종류 수 증가
        eatenSushi[sushiTypes[i]]++;
    }

    int maxTypes = 0;
    //쿠폰 스시 적용하여 최대 종류 수 갱신
    if (eatenSushi[couponSushi] == 0)
        maxTypes = max(maxTypes, currentTypes + 1);
    else
        maxTypes = max(maxTypes, currentTypes);

    //슬라이딩 윈도우 기법으로 구간을 한 칸씩 이동하며 남은 구간 탐색
    for (int i = 1; i < sushiTypes.size(); i++) {
        //이전 구간의 첫 번째 스시 제거
        eatenSushi[sushiTypes[i - 1]]--;
        if (eatenSushi[sushiTypes[i - 1]] == 0) currentTypes--;

        //새로운 스시 추가
        int newSushi = sushiTypes[(i + consecutivePlates - 1) % sushiTypes.size()];
        if (eatenSushi[newSushi] == 0) currentTypes++;
        eatenSushi[newSushi]++;

        //쿠폰 스시 적용하여 최대 종류 수 갱신
        if (eatenSushi[couponSushi] == 0)
            maxTypes = max(maxTypes, currentTypes + 1);
        else
            maxTypes = max(maxTypes, currentTypes);
    }

    return maxTypes;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int numPlates, numSushiTypes, consecutivePlates, couponSushi;
    cin >> numPlates >> numSushiTypes >> consecutivePlates >> couponSushi;

    vector<int> sushiTypes(numPlates);
    for (int i = 0; i < numPlates; i++) {
        cin >> sushiTypes[i];
    }

    //최대 스시 종류 계산 및 출력
    cout << calculateMaxSushiTypes(sushiTypes, numSushiTypes, consecutivePlates, couponSushi);

    return 0;
}
