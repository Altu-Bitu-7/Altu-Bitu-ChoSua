#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> //abs() 함수 사용을 위한 헤더 파일

using namespace std;
using ll = long long;

//세 수의 합이 0에 가장 가까운 세 수를 찾는 함수
tuple<ll, ll, ll> findClosestTripleSum(const vector<ll>& numbers) {
    int N = numbers.size();
    ll minDifference = 2e18;  //초기값을 매우 큰 수로 설정
    ll firstNum = -1, secondNum = -1, thirdNum = -1;

    //숫자 목록을 정렬하여 투 포인터 탐색에 활용
    for (int i = 0; i < N - 2; i++) {
        int left = i + 1;
        int right = N - 1;

        while (left < right) {
            ll threeSum = numbers[i] + numbers[left] + numbers[right];

            //합이 0이면 즉시 결과 반환
            if (threeSum == 0) {
                return {numbers[i], numbers[left], numbers[right]};
            }

            //0과의 차이가 최소인 경우 갱신
            if (abs(threeSum) < minDifference) {
                minDifference = abs(threeSum);
                firstNum = numbers[i];
                secondNum = numbers[left];
                thirdNum = numbers[right];
            }

            //세 수의 합이 양수면 오른쪽 포인터를 왼쪽으로 이동
            if (threeSum > 0) {
                right--;
            }
            //세 수의 합이 음수면 왼쪽 포인터를 오른쪽으로 이동
            else {
                left++;
            }
        }
    }

    return {firstNum, secondNum, thirdNum};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;
    vector<ll> numbers(N);
    for (auto& num : numbers) {
        cin >> num;
    }

    //입력된 숫자 목록을 정렬
    sort(numbers.begin(), numbers.end());

    //세 수의 합이 0에 가장 가까운 세 수를 찾아 출력
    auto [firstNum, secondNum, thirdNum] = findClosestTripleSum(numbers);
    cout << firstNum << " " << secondNum << " " << thirdNum << "\n";

    return 0;
}
