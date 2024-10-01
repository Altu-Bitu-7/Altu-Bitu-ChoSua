#include<iostream>
#define MAX 1010
using namespace std;

int numElements;   //배열 크기
int arr[MAX];      //배열
int lis[MAX];      //가장 긴 증가하는 부분 수열의 길이를 저장하는 배열

int getMax(int a, int b) {  //두 수 중 더 큰 값을 반환하는 함수
    return (a > b) ? a : b;
}

void calculateLIS() {  //가장 긴 증가하는 부분 수열의 길이를 계산하는 함수
    int maxLength = 0;

    for (int i = 1; i <= numElements; i++) {
        lis[i] = 1;      //각 원소는 최소 길이 1의 수열을 가질 수 있음
        for (int j = i - 1; j >= 1; j--) {
            if (arr[i] > arr[j]) {
                lis[i] = getMax(lis[i], lis[j] + 1);
            }
        }
        maxLength = getMax(lis[i], maxLength);
    }

    cout << maxLength << endl;   //길이 출력
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> numElements;
    for (int i = 1; i <= numElements; i++) {
        cin >> arr[i];
    }
    calculateLIS();   //가장 긴 부분 수열 계산, 출력

    return 0;
}
