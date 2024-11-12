#include <iostream>
#include <algorithm>

using namespace std;

const int MAX_ARRAY_SIZE = 200001;
const int MAX_DUPLICATE_SIZE = 100001;

int arr[MAX_ARRAY_SIZE];   //입력 배열
int duplicates[MAX_DUPLICATE_SIZE];  //중복된 원소 개수를 세는 배열

//최장 부분 수열의 길이를 찾는 함수
int findMaxSubsequenceLength(int n, int k) {
    int maxLength = 0;
    int left = 1, right = 1;

    //슬라이딩 윈도우 방식으로 중복 개수를 관리하며 부분 수열의 길이를 탐색
    while (left <= right && right <= n) {
        //현재 숫자가 중복 제한에 걸리지 않으면 오른쪽 포인터 이동
        if (duplicates[arr[right]] < k) {
            duplicates[arr[right++]]++;  //해당 숫자의 중복 횟수를 증가
            maxLength = max(maxLength, right - left); //최대 길이 갱신
        }
        //현재 숫자가 중복 제한에 걸리면 왼쪽 포인터 이동
        else if (duplicates[arr[right]] == k) {
            duplicates[arr[left++]]--;  //왼쪽 숫자의 중복 횟수를 감소
        }
    }
    return maxLength;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    //최장 부분 수열의 길이를 계산하고 출력
    cout << findMaxSubsequenceLength(n, k);

    return 0;
}
