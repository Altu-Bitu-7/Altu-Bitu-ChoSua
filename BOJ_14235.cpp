#include <iostream>
#include <queue>
using namespace std;

//최대 힙을 전역 변수로 선언
priority_queue<int, vector<int>> maxHeap;

//선물 추가 처리 함수
void addGifts(int count) {
    for (int i = 0; i < count; i++) {
        int gift;
        cin >> gift;  //사용자로부터 선물의 값을 입력 받음
        maxHeap.push(gift);  //입력받은 선물을 최대 힙에 추가
    }
}

//가장 큰 선물 처리 함수, 최대 힙에서 가장 큰 값을 반환하고 힙에서 제거
int getMaxGift() {
    if (maxHeap.empty()) {
        return -1;  //힙이 비어 있으면 -1 반환
    } else {
        int topGift = maxHeap.top();  //힙에서 가장 큰 값을 가져옴
        maxHeap.pop();  //힙에서 가장 큰 값을 제거
        return topGift;  //가장 큰 값을 반환
    }
}

//입력에 따라 선물을 추가하거나 가장 큰 선물을 반환하는 함수
int processGiftOperation(int operation) {
    if (operation == 0) {
        return getMaxGift();  //가장 큰 선물 처리
    } else {
        addGifts(operation);  //선물 추가
        return -2;  //출력하지 않기 위한 값
    }
}

int main() {
    ios::sync_with_stdio(false); //수행 시간 줄여줌!! (108ms -> 20ms)
    cin.tie(NULL);
    cout.tie(NULL);

    //입력
    int n, operation;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> operation;  //연산 종류 입력
        int result = processGiftOperation(operation);  //연산 수행
        if (result != -2) {
            cout << result << "\n";
        }
    }

    return 0;
}
