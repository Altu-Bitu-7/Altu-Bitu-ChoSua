#include <iostream>
using namespace std;

//주어진 배열을 기반으로 최종 결과를 계산하는 함수
long long calculateResult(int arr[], int n) {
    long long ans = arr[n - 1]; //가장 마지막 값
    for (int i = n - 2; i >= 0; i--) { //역순으로 탐색
        if (ans % arr[i] == 0) {
            continue; //나누어 떨어지면 넘어감
        } else {
            ans = arr[i] * (ans / arr[i] + 1); //최소 배수를 계산
        }
    }
    return ans; //최종 결과 반환
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int arr[300000]; //배열 선언

    //배열 입력
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << calculateResult(arr, n) << "\n";

    return 0;
}
