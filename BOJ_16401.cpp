#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//과자를 나눠줄 수 있는 최대 길이를 이진 탐색을 통해 찾는 함수
int getMaxSnackLength(int numPeople, const vector<int>& snackLengths) {
    int left = 1, right = *max_element(snackLengths.begin(), snackLengths.end());
    int maxSnackLength = 0;

    while (left <= right) {
        int mid = (left + right) / 2; //중앙값(과자 길이)
        int count = 0;

        //각 과자 길이를 현재 중앙값(mid)로 나눠 몇 명에게 나눠줄 수 있는지 계산
        for (int length : snackLengths) {
            count += length / mid;
        }

        //나눠줄 수 있는 사람이 원하는 수(numPeople) 이상인 경우
        if (count >= numPeople) {
            maxSnackLength = mid;  //가능한 과자 길이 중 최대값 저장
            left = mid + 1;   //더 큰 길이로 탐색
        } else {
            right = mid - 1;   //더 작은 길이로 탐색
        }
    }
    return maxSnackLength;
}

// 사용자 입력을 받아 과자 길이 배열을 반환하는 함수
vector<int> getInputArray(int size) {
    vector<int> array(size);
    for (int& length : array) {
        cin >> length;
    }
    return array;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //인원 수와 과자 개수 입력
    int numPeople, numSnacks;
    cin >> numPeople >> numSnacks;

    //과자 길이 배열 입력
    vector<int> snackLengths = getInputArray(numSnacks);

    //나눠줄 수 있는 최대 과자 길이를 계산하고 출력
    int result = getMaxSnackLength(numPeople, snackLengths);
    cout << result << "\n";

    return 0;
}
