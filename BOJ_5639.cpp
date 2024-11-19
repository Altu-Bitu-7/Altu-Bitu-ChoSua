#include <iostream>
#include <vector>

using namespace std;
int binaryTree[10000];

//후위 순회 함수
void postOrderTraversal(int start, int end) {
    if (start >= end) {
        return;
    }
    if (start == end - 1) {
        cout << binaryTree[start] << '\n';
        return;
    }

    int idx = start + 1;
    while (idx < end) {
        if (binaryTree[start] < binaryTree[idx]) {
            break;
        }
        idx++;
    }

    //왼쪽 부분 트리 후위 순회
    postOrderTraversal(start + 1, idx);
    //오른쪽 부분 트리 후위 순회
    postOrderTraversal(idx, end);
    //현재 노드 방문
    cout << binaryTree[start] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int num;
    vector<int> inputNumbers;
    while (cin >> num) {
        inputNumbers.push_back(num);
    }

    //배열에 입력값을 저장
    for (int i = 0; i < inputNumbers.size(); i++) {
        binaryTree[i] = inputNumbers[i];
    }

    //후위 순회 시작
    postOrderTraversal(0, inputNumbers.size());

    return 0;
}
